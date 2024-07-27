set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")

add_subdirectory("graph")
add_subdirectory("dsa")
