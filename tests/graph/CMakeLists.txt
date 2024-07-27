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
