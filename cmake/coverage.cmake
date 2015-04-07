## Copyright (c) 2012 - 2015, Lars Bilke
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without modification,
## are permitted provided that the following conditions are met:
##
## 1. Redistributions of source code must retain the above copyright notice, this
##    list of conditions and the following disclaimer.
##
## 2. Redistributions in binary form must reproduce the above copyright notice,
##    this list of conditions and the following disclaimer in the documentation
##    and/or other materials provided with the distribution.
##
## 3. Neither the name of the copyright holder nor the names of its contributors
##    may be used to endorse or promote products derived from this software without
##    specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
## ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
## WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
## DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
## ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
## ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
##
##
## 2012-01-31, Lars Bilke
## - Enable Code Coverage
##
## 2013-09-17, Joakim Söderberg
## - Added support for Clang.
## - Some additional usage instructions.
##
## USAGE:

## 0. (Mac only) If you use Xcode 5.1 make sure to patch geninfo as described here:
##      http://stackoverflow.com/a/22404544/80480
##
## 1. Copy this file into your cmake modules path.
##
## 2. Add the following line to your CMakeLists.txt:
##      INCLUDE(CodeCoverage)
##
## 3. Set compiler flags to turn off optimization and enable coverage:
##    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
##    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
##
## 3. Use the function SETUP_TARGET_FOR_COVERAGE to create a custom make target
##    which runs your test executable and produces a lcov code coverage report:
##    Example:
##    SETUP_TARGET_FOR_COVERAGE(
##               my_coverage_target  ## Name for custom target.
##               test_driver         ## Name of the test driver executable that runs the tests.
##                                   ## NOTE! This should always have a ZERO as exit code
##                                   ## otherwise the coverage generation will not complete.
##               coverage            ## Name of output directory.
##               )
##
## 4. Build a Debug build:
##    cmake -DCMAKE_BUILD_TYPE=Debug ..
##    make
##    make my_coverage_target
##
##

FUNCTION(SETUP_TARGET_FOR_COVERAGE root)

    set(boost_filter "'${Boost_INCLUDE_DIRS}/*'")

    ## Setup target
    ADD_CUSTOM_TARGET( coverage

        ## Cleanup lcov
        COMMAND ${CMAKE_COMMAND} -E remove coverage.info coverage.info.cleaned
        COMMAND ${LCOV_PATH} --directory . --zerocounters

        ## Run tests
        COMMAND ctest -R ^${root}.*.coverage

        ## Capturing lcov counters and generating report
        COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.info
        COMMAND ${LCOV_PATH} --remove coverage.info 'tests/*' '/usr/*' ${boost_filter} '*/_deps/*' --output-file coverage.info.cleaned
        COMMAND ${GENHTML_PATH} --demangle --no-branch-coverage -o coverage coverage.info.cleaned

        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Resetting code coverage counters to zero.\nProcessing code coverage counters and generating report."
    )

    ## Show info where to find the report
    ADD_CUSTOM_COMMAND(TARGET coverage POST_BUILD
        COMMAND ;
        COMMENT "Open ./coverage/index.html in your browser to view the coverage report."
    )
ENDFUNCTION()

IF(NOT CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE(STATUS "[coverage] Compiler does not support gcov. coverage targets disabled")
    return()
ENDIF() ## NOT CMAKE_COMPILER_IS_GNUCXX

## Check prereqs
FIND_PROGRAM( GCOV_PATH gcov )
FIND_PROGRAM( LCOV_PATH lcov )
FIND_PROGRAM( GENHTML_PATH genhtml )
FIND_PROGRAM( GCOVR_PATH gcovr PATHS ${CMAKE_SOURCE_DIR}/tests)

IF(NOT GCOV_PATH)
  MESSAGE(STATUS "[coverage] gcov not found! Coverage disabled")
  return()
ENDIF() ## NOT GCOV_PATH

IF(NOT LCOV_PATH)
  MESSAGE(STATUS "[coverage] lcov not found! Coverage disabled")
  return()
ENDIF() ## NOT LCOV_PATH

IF(NOT GENHTML_PATH)
  MESSAGE(STATUS "[coverage] genhtml not found! Coverage disabled")
  return()
ENDIF() ## NOT GENHTML_PATH

SET(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )
SET(CMAKE_C_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    "-lgcov -fprofile-arcs "
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )
SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    "-lgcov -fprofile-arcs "
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )

MARK_AS_ADVANCED(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE )

SET(COVERAGE_SUPPORTED 1)
