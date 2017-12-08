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
    b.insert(215);
    EXPECT_TRUE(b.search(12213));
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