set(TARGET_NAME "01-simple-library")
set(COVERAGE_NAME "01-coverage")
set(COVERAGE_TARGET "01-coverage-simple-library")
set(SOURCE_DIR_MAIN "${01-simple-library_SOURCE_DIR}")
set(SOURCES ${01-source-files})

message(INFO ${SOURCES})

set(TEST_SOURCES AddTestCase.h AddTestCase.cpp LeapTestCase.cpp LeapTestCase.h)
run_coverage(
    "${TEST_SOURCES}"
    "${SOURCES}"
    "${COVERAGE_TARGET}"
    "${TARGET_NAME}"
    "${COVERAGE_NAME}"
)