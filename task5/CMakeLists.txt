cmake_minimum_required(VERSION 3.8)
project(Testing CXX)

include(ExternalProject)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake)
include(CodeCoverage)

set(EXTERNAL_INSTALL_LOCATION ${Testing_SOURCE_DIR}/3rdparty)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Testing_SOURCE_DIR}/bin)
set(Boost_USE_MULTITHREADED OFF)

SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
# SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -lgcov" )
if (APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") 
endif()

ExternalProject_Add(
    googletest_repo
    GIT_REPOSITORY https://github.com/google/googletest.git
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
)

if (APPLE)

	set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1" CACHE INTERNAL "")
	set(OPENSSL_LIBRARIES "/usr/local/opt/openssl@1.1/lib" CACHE INTERNAL "")
	ExternalProject_Add(
		cpr_repo
		GIT_REPOSITORY https://github.com/akhtyamovpavel/cpr.git
		CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD} -DOPENSSL_ROOT_DIR=${OPENSSL_ROOT_DIR} -DOPENSSL_LIBRARIES=${OPENSSL_LIBRARIES} -DCMAKE_POSITION_INDEPENDENT_CODE=ON
	)
else()
	ExternalProject_Add(
		cpr_repo
		GIT_REPOSITORY https://github.com/akhtyamovpavel/cpr.git
		CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD} -DCMAKE_POSITION_INDEPENDENT_CODE=ON
	)
endif()

find_package(Boost COMPONENTS filesystem system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
include_directories(${CPR_INCLUDE_DIRS})
message("Boost libraries are located at ${Boost_LIBRARY_DIRS}")
message("Boost libraries are ${Boost_LIBRARIES}")

find_package(PythonInterp 3 REQUIRED)

set(PYTHON_EXECUTABLE "python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")

message(${PYTHON_EXECUTABLE})

add_custom_target(
    InstallDeps
    COMMAND ${Testing_SOURCE_DIR}/install_deps.sh ${PYTHON_EXECUTABLE}
    DEPENDS install_deps.sh
    WORKING_DIRECTORY ${Testing_SOURCE_DIR}
    COMMENT "Installing dependencies"
)

add_custom_target(coverage_report)

add_dependencies(coverage_report InstallDeps)

function(run_coverage test_sources sources coverage_target target_name coverage_name)
    message(INFO test sources ${test_sources})
    set(test_name "${target_name}-test")
    message(INFO sources "${sources}")
    add_executable(${test_name} ${test_sources} ${sources})

#    set_target_properties(${test_name} PROPERTIES LINKER_LANGUAGE CXX)

    target_link_libraries(
		${test_name} gtest_main gtest gmock Threads::Threads Boost::filesystem cpr curl
	)

    setup_target_for_coverage_gcovr(
            ${coverage_target} ${target_name} ${test_name} ${coverage_name}
    )
    add_dependencies(${test_name} googletest_repo InstallDeps cpr_repo)

    add_dependencies(coverage_report ${coverage_target})
endfunction()


include_directories(include)

add_subdirectory(src/00-aplusb)
add_subdirectory(src/01-simple-library)
add_subdirectory(src/02-tree)
add_subdirectory(src/03-weather)
add_subdirectory(examples)

add_subdirectory(tests)


