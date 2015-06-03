# Library

lib_LTLIBRARIES = libsorting.la

libsorting_la_SOURCES = merge_sort.cpp

# Unit test

noinst_PROGRAMS = test_merge_sort

test_merge_sort_SOURCES = merge_sort.cpp test_merge_sort.cpp
test_merge_sort_CXXFLAGS = -Wall -Wextra -pthread --std=c++11
test_merge_sort_LDADD = -lpthread -lgtest_main -lgtest 

TESTS = test_merge_sort
