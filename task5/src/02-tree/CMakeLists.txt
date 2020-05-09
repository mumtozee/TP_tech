project(02-tree)

set(02-source-files "${PROJECT_SOURCE_DIR}/Tree.cpp" CACHE INTERNAL "")

add_library(
    02-tree SHARED ${02-source-files} ${Testing_SOURCE_DIR}/include/Tree.h
)

target_link_libraries(
	02-tree Boost::filesystem
)


