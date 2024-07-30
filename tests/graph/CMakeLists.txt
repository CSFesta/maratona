add_executable(prim prim.cpp)
target_link_libraries(prim GTest::gtest_main Prim)
gtest_discover_tests(prim PROPERTIES TIMEOUT 600)

add_executable(dijkstra dijkstra.cpp)
target_link_libraries(dijkstra GTest::gtest_main Dijkstra)
gtest_discover_tests(dijkstra PROPERTIES TIMEOUT 600)

add_executable(dfs dfs.cpp)
target_link_libraries(dfs GTest::gtest_main Dfs)
gtest_discover_tests(dfs PROPERTIES TIMEOUT 600)

add_executable(scc scc.cpp)
target_link_libraries(scc GTest::gtest_main Scc)
gtest_discover_tests(scc PROPERTIES TIMEOUT 600)
