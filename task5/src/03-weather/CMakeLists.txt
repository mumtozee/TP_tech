project(03-weather)

set(03-source-files "${PROJECT_SOURCE_DIR}/Weather.cpp" CACHE INTERNAL "")

add_library(
    03-weather SHARED ${03-source-files} ${Testing_SOURCE_DIR}/include/Weather.h
)

target_link_libraries(
	03-weather cpr curl
)

add_dependencies(
	03-weather
	cpr_repo
)

