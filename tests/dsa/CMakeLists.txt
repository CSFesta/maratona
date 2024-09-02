add_executable(heap heap.cpp)
target_link_libraries(heap GTest::gtest_main Heap)
gtest_discover_tests(heap PROPERTIES TIMEOUT 600)

add_executable(mdc mdc.cpp)
target_link_libraries(mdc GTest::gtest_main Mdc)
gtest_discover_tests(mdc PROPERTIES TIMEOUT 600)

add_executable(disjoint disjoint.cpp)
target_link_libraries(disjoint GTest::gtest_main Disjoint)
gtest_discover_tests(disjoint PROPERTIES TIMEOUT 600)

add_executable(pow pow.cpp)
target_link_libraries(pow GTest::gtest_main Pow)
gtest_discover_tests(pow PROPERTIES TIMEOUT 600)

