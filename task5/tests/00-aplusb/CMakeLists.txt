add_executable(00-test-aplusb test.cpp)

target_link_libraries(00-test-aplusb gtest_main gtest Threads::Threads)

setup_target_for_coverage_gcovr(00-coverage-aplusb ${00-aplusb_SOURCE_DIR} 00-test-aplusb 00-coverage)
add_dependencies(00-test-aplusb googletest_repo InstallDeps)

add_dependencies(coverage_report 00-coverage-aplusb)