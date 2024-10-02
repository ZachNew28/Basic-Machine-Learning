// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"


TEST(test_empty) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());

    tree.insert(3);

    ASSERT_FALSE(tree.empty());
}

TEST(test_size) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.size() == 0);

    tree.insert(1);
    ASSERT_TRUE(tree.size() == 1);

    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    ASSERT_TRUE(tree.size() == 5);
}

TEST(test_height) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.height() == 0);

    tree.insert(1);
    ASSERT_TRUE(tree.height() == 1);

    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    ASSERT_TRUE(tree.height() == 5);

    tree.insert(-1);
    tree.insert(-2);
    tree.insert(-3);
    tree.insert(-4);
    tree.insert(-5);
    ASSERT_TRUE(tree.height() == 6);
}

TEST(test_copy) {
    BinarySearchTree<int> tree;
    BinarySearchTree<int>::Iterator it = tree.insert(1);

    BinarySearchTree<int> tree2(tree);

    BinarySearchTree<int>::Iterator it2 = tree2.find(1);

    ASSERT_TRUE(*it == *it2);

    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    BinarySearchTree<int> tree3(tree);

    it2 = tree3.find(1);

    for (int i = 0; i < tree.size(); i++) {
        ASSERT_TRUE(*it == *it2);
        it++;
        it2++;
    }
}

TEST(test_destroy) {
    BinarySearchTree<int> tree;
    BinarySearchTree<int> tree2;

    tree.insert(1);
    tree.insert(2);
    tree2.insert(3);

    tree2 = tree;

    BinarySearchTree<int>::Iterator it = tree2.find(3);

    ASSERT_TRUE(it == tree2.end());
}

TEST(test_find) {
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.find(1) == tree.end());

    tree.insert(1);
    ASSERT_TRUE(*tree.find(1) == 1);
    ASSERT_TRUE(tree.find(2) == tree.end());
}

TEST(test_insert) {
    BinarySearchTree<int> tree;
    tree.insert(1);

    ASSERT_TRUE(*tree.find(1) == 1);

    BinarySearchTree<int>::Iterator it = tree.insert(-1);

    ASSERT_TRUE(*tree.find(-1) == -1);
    ASSERT_TRUE(*(++it) == 1);

    tree.insert(3);
    ASSERT_TRUE(*(++it) == 3);
}

TEST(test_min_element) {
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.min_element() == tree.end())

    tree.insert(3);
    ASSERT_TRUE(*tree.min_element() == 3);

    tree.insert(0);
    ASSERT_TRUE(*tree.min_element() == 0);

    tree.insert(1);
    ASSERT_TRUE(*tree.min_element() == 0);
}

TEST(test_max_element) {
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.max_element() == tree.end());

    tree.insert(3);
    ASSERT_TRUE(*tree.max_element() == 3);

    tree.insert(5);
    ASSERT_TRUE(*tree.max_element() == 5);

    tree.insert(4);
    ASSERT_TRUE(*tree.max_element() == 5);
}

TEST(test_check_sorting_invariant) {
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.check_sorting_invariant());

    tree.insert(0);
    tree.insert(1);
    tree.insert(2);

    ASSERT_TRUE(tree.check_sorting_invariant());

    *tree.begin() = 4;

    ASSERT_FALSE(tree.check_sorting_invariant());

    *tree.begin() = 0;
    *(++tree.begin()) = -5;

    ASSERT_FALSE(tree.check_sorting_invariant());
}

TEST(test_traverse_inorder) {
    BinarySearchTree<int> tree;

    tree.traverse_inorder(std::cout);

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);

    tree.traverse_inorder(std::cout);
}

TEST(test_traverse_preorder) {
    BinarySearchTree<int> tree;

    tree.traverse_preorder(std::cout);

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);

    tree.traverse_inorder(std::cout);
}

TEST(test_min_greater_than) {
    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.min_greater_than(4) == tree.end());

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);

    ASSERT_TRUE(*tree.min_greater_than(0) == 1);
    ASSERT_TRUE(tree.min_greater_than(5) == tree.end());
    ASSERT_TRUE(*tree.min_greater_than(2) == 3);
}

TEST_MAIN()
