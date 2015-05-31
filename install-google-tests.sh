#!/bin/bash

export GTEST_URL=http://googletest.googlecode.com/files/gtest-1.7.0.zip
export TMP_PATH=/tmp

function try()
{
  [[ $- = *e* ]]; SAVED_OPT_E=$?
  set +e
}

function catch()
{
  export ex_code=$?
  (( $SAVED_OPT_E )) && set +e
  if [[ $ex_code -eq 0 ]]
  then
    echo "ok"
  else
    echo "fail $ex_code"
    exit 1
  fi
}

# Make sure only root can run our script
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root" 1>&2
  exit 1
fi

echo -n "1. Downloading gtest... "
try
(
  mkdir -p $TMP_PATH
  cd $TMP_PATH
  wget $GTEST_URL -O gtest.zip &> /dev/null
  echo -n "extracting... "
  rm -rf gtest
  unzip gtest.zip -d gtest > /dev/null
  rm -f gtest.zip
)
catch

echo -n "2. Building gtest... "
try
(
  cd $TMP_PATH/gtest/*
  echo -n "configure... "
  ./configure &> make.log
  echo -n "make... "
  make &>> make.log
)
catch

echo -n "3. Installing libs... "
try
(
  cd $TMP_PATH/gtest/*
  cp -a include/gtest /usr/include
  cp -a lib/.libs/* /usr/lib/
  # echo "ldconfig:"
  # ldconfig -v 2> /dev/null | grep 'libgtest'
)
catch

echo -n "4. Cleaning... "
(
  cd $TMP_PATH
  rm -rf gtest.zip gtest
)
catch

echo "**Install ok**"
