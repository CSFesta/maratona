add_executable(
  prim
  prim.cpp
)
target_link_libraries(
  prim
  GTest::gtest_main
  Prim
)

gtest_discover_tests(prim PROPERTIES TIMEOUT 600)

add_executable(
  dijkstra
  dijkstra.cpp
)
target_link_libraries(
  dijkstra
  GTest::gtest_main
  Dijkstra
)

gtest_discover_tests(dijkstra PROPERTIES TIMEOUT 600)
