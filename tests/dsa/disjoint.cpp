#include "../../src/dsa/disjoint.cpp"
#include <gtest/gtest.h>

TEST(DisjointSetTest, FullTest) {
    vector<node> test = make_set(8);
    for (u32 i = 0; i < test.size(); ++i) {
        ASSERT_EQ(test[i].parent, i);
        ASSERT_EQ(test[i].size, 1);
    }
    merge(test, 1, 2);
    ASSERT_EQ(test[1].size, 2);
    ASSERT_EQ(test[2].parent, 1);
    ASSERT_EQ(find(test, 2), 1);
    ASSERT_EQ(find(test, 1), 1);
    merge(test, 1, 0);
    merge(test, 1, 3);
    merge(test, 1, 4);
    merge(test, 1, 5);
    merge(test, 1, 6);
    merge(test, 1, 7);
    ASSERT_EQ(test[1].size, 8);
    ASSERT_EQ(find(test, 7), 1);
    ASSERT_EQ(find(test, 6), 1);
    ASSERT_EQ(find(test, 5), 1);
    ASSERT_EQ(find(test, 4), 1);
    ASSERT_EQ(find(test, 3), 1);
    ASSERT_EQ(find(test, 2), 1);
    ASSERT_EQ(find(test, 0), 1);
}
