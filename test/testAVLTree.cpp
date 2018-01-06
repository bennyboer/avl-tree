#include "testAVLTree.h"
#include <memory>

using namespace std;

// Insert-Tests
TEST(AVLTreeTest, One_Node) {
    AVLTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123));
    EXPECT_FALSE(b.search(-123));
}

TEST(AVLTreeTest, Two_Nodes_Lower) {
    AVLTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    b.insert(215);
    EXPECT_TRUE(b.search(215));
}

TEST(AVLTreeTest, Two_Nodes_Greater) {
    AVLTree b;
    b.insert(12);
    b.insert(215);
    EXPECT_TRUE(b.search(12));
    EXPECT_TRUE(b.search(215));
}

TEST(AVLTreeTest, Three_Nodes) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
}

TEST(AVLTreeTest, Insert_BalanceOneInsertLeft) {
    AVLTree b;
    b.insert(5);
    b.insert(7);
    b.insert(4);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(7));
    EXPECT_TRUE(b.search(4));
}

TEST(AVLTreeTest, Insert_BalanceMinusOneInsertRight) {
    AVLTree b;
    b.insert(5);
    b.insert(4);
    b.insert(7);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(4));
    EXPECT_TRUE(b.search(7));
}

TEST(AVLTreeTest, Insert_BalanceZeroToOne) {
    AVLTree b;
    b.insert(5);
    b.insert(4);
    b.insert(7);
    b.insert(8);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(4));
    EXPECT_TRUE(b.search(7));
    EXPECT_TRUE(b.search(8));
}

TEST(AVLTreeTest, Insert_BalanceZeroToMinnusOne) {
    AVLTree b;
    b.insert(5);
    b.insert(4);
    b.insert(7);
    b.insert(2);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(4));
    EXPECT_TRUE(b.search(7));
    EXPECT_TRUE(b.search(2));
}

TEST(AVLTreeTest, Insert_RotateRight) {
    AVLTree b;
    b.insert(5);
    b.insert(4);
    b.insert(3);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(4));
    EXPECT_TRUE(b.search(3));
}

TEST(AVLTreeTest, Insert_RotateLeftRight) {
    AVLTree b;
    b.insert(5);
    b.insert(3);
    b.insert(4);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(3));
    EXPECT_TRUE(b.search(4));
}

TEST(AVLTreeTest, Insert_RotateOnlyLeft) {
    AVLTree b;
    b.insert(5);
    b.insert(7);
    b.insert(8);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(7));
    EXPECT_TRUE(b.search(8));
}

TEST(AVLTreeTest, Insert_RotateRightLeft) {
    AVLTree b;
    b.insert(5);
    b.insert(9);
    b.insert(6);
    EXPECT_TRUE(b.search(5));
    EXPECT_TRUE(b.search(9));
    EXPECT_TRUE(b.search(6));
}