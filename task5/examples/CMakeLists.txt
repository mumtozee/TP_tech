
add_executable(
    00-aplusb-bin 00-main.cpp
)
add_executable(01-simple-library-bin 01-main.cpp)
target_link_libraries(01-simple-library-bin 01-simple-library)

add_executable(02-tree-bin 02-main.cpp)
target_link_libraries(02-tree-bin 02-tree Boost::filesystem)

add_executable(03-weather-bin 03-main.cpp)
target_link_libraries(03-weather-bin 03-weather cpr curl)
