set(TARGET_NAME "02-tree")
set(COVERAGE_NAME "02-coverage")
set(COVERAGE_TARGET "02-coverage-tree")
set(SOURCE_DIR_MAIN "${02-tree_SOURCE_DIR}")
set(SOURCES ${02-source-files})

message(INFO ${SOURCES})

set(TEST_SOURCES TreeTestCase.h TreeTestCase.cpp)
run_coverage(
        "${TEST_SOURCES}"
        "${SOURCES}"
        "${COVERAGE_TARGET}"
        "${TARGET_NAME}"
        "${COVERAGE_NAME}"
)