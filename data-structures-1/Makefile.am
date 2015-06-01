# Library

lib_LTLIBRARIES = libdatastruct.la

libdatastruct_la_SOURCES = list.cpp

# Unit test

noinst_PROGRAMS = test_list

test_list_SOURCES = list.cpp list-test.cpp
test_list_CXXFLAGS = -Wall -Wextra -pthread --std=c++11
test_list_LDADD = -lpthread -lgtest_main -lgtest 

TESTS = test_list
