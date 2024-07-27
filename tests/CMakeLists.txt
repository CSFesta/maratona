set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address -g")

add_subdirectory("graph")
add_subdirectory("dsa")
