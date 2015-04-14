##===================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================
cmake_minimum_required(VERSION 2.8.7)

##===================================================================================================
## Setup project
##===================================================================================================
project(Boost.Dispatch CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

##===================================================================================================
## Prevent in-source build
##===================================================================================================
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
  message( FATAL_ERROR "Building in-source, not recommended! Build in a separate directory." )
endif()

##===================================================================================================
## Search for packages.
##===================================================================================================
find_package(Boost   1.57)
find_package(Doxygen QUIET)

##===================================================================================================
## Install pre-commit git hook
##===================================================================================================
execute_process(COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/script/git/pre-commit
                ${PROJECT_SOURCE_DIR}/.git/hooks
               )

##===================================================================================================
## Compute version string and mode
##===================================================================================================
include(parse_revision)

##===================================================================================================
## Add dependency to NSTest
##===================================================================================================
include(register_dependency)
register_dependency( NSTest https://github.com/NumScale/nstest.git )

##===================================================================================================
## Add include directories
##===================================================================================================
include_directories ( ${PROJECT_SOURCE_DIR}/include
                      ${Boost_INCLUDE_DIRS}
                      ${dep_path}/include
                    )

##===================================================================================================
## Setup Documentation
##===================================================================================================
add_subdirectory(doc)

##===================================================================================================
## Setup Unit & Coverage Test
##===================================================================================================
enable_testing()
include(coverage)
setup_target_for_coverage(boost.dispatch)

add_custom_target(unit)
add_subdirectory(test)