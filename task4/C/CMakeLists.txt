project(C)


add_executable(CTestExe main_test.cpp tests.cpp)

target_link_libraries(CTestExe gtest_main ClassLib)
target_include_directories(CTestExe PRIVATE ${Task4_SOURCE_DIR})


add_executable(C main.cpp)

target_link_libraries(C ClassLib)
target_include_directories(C PRIVATE ${Task4_SOURCE_DIR})
