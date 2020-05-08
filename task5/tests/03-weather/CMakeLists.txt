set(TARGET_NAME "03-weather")
set(COVERAGE_NAME "03-coverage")
set(COVERAGE_TARGET "03-coverage-weather")
set(SOURCE_DIR_MAIN "${03-weather_SOURCE_DIR}")
set(SOURCES ${03-source-files})

message(INFO ${SOURCES})

set(TEST_SOURCES WeatherTestCase.h WeatherTestCase.cpp WeatherMock.h WeatherMock.cpp)
run_coverage(
        "${TEST_SOURCES}"
        "${SOURCES}"
        "${COVERAGE_TARGET}"
        "${TARGET_NAME}"
        "${COVERAGE_NAME}"
)