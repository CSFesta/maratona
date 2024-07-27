add_executable(
  heap
  heap.cpp
)
target_link_libraries(
  heap
  GTest::gtest_main
  Heap
)

gtest_discover_tests(heap PROPERTIES TIMEOUT 600)
