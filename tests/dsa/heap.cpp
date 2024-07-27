#include "../../src/dsa/heap.cpp"
#include <gtest/gtest.h>

TEST(HeapSort, Dsa) {
    std::vector<int> test = {5, 21, 456, 12, 34, 1, 8, 9, 12, 4, 2, 65, 4, 5};
    std::vector<int> expected = {1, 2,  4,  4,  5,  5,  8,
                                 9, 12, 12, 21, 34, 65, 456};

    heapify(test);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));

    sort(test);

    EXPECT_TRUE(std::is_sorted(test.begin(), test.end()));

    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i << " test has "
            << test[i] << " where it should have " << expected[i];
    }
}

TEST(HeapSortRegression, Dsa) {
    std::vector<int> test = {5, 2, 6};
    std::vector<int> expected = {2, 5, 6};

    heapify(test);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));

    sort(test);

    EXPECT_TRUE(std::is_sorted(test.begin(), test.end()));

    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], test[i])
            << "Vectors expected and test differ at index " << i << " test has "
            << test[i] << " where it should have " << expected[i];
    }
}

TEST(HeapPushPop, Dsa) {
    std::vector<int> test;

    push_heap(test, 4);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 2);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 0);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 1);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 0);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 3);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 6);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 0);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 5);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));
    push_heap(test, 0);

    EXPECT_TRUE(std::is_heap(test.begin(), test.end()));

    sort(test);

    EXPECT_TRUE(std::is_sorted(test.begin(), test.end()));
    
    EXPECT_EQ(0, pop_heap(test));
}
