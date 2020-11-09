cmake_minimum_required (VERSION 2.6)

project (essential-cplusplus)

# C++11
set (CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(src/01_basic_programming)
ADD_SUBDIRECTORY(src/02_procedure_programming)
ADD_SUBDIRECTORY(src/03_generic_programming)
ADD_SUBDIRECTORY(src/04_object_based_programming)
ADD_SUBDIRECTORY(src/05_object_oriented_programming)
ADD_SUBDIRECTORY(src/06_programming_with_templates)
ADD_SUBDIRECTORY(src/07_exception_handling)
