#include "testAVLTree.h"
#include <memory>

using namespace std;

///////////////////////
//Search-Test
///////////////////////
TEST(AvlTreeTest, Search_EmptyTree) {
    AVLTree t;
    EXPECT_FALSE(t.search(5));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Search_NotExists) {
    AVLTree t;
    t.insert(7);
    EXPECT_FALSE(t.search(5));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Search_ExistsOneNode) {
    AVLTree t;
    t.insert(10);
    EXPECT_TRUE(t.search(10));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Search_ExistsGreater) {
    AVLTree t;
    t.insert(7);
    t.insert(11);
    t.insert(4);
    t.insert(3);
    t.insert(12);
    EXPECT_TRUE(t.search(12));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Search_ExistsLower) {
    AVLTree t;
    t.insert(9);
    t.insert(13);
    t.insert(6);
    t.insert(5);
    EXPECT_TRUE(t.search(5));
    EXPECT_TRUE(t.isBalanced());
}

///////////////////////
// Insert-Tests
///////////////////////


TEST(AvlTreeTest, Insert_InEmptyTree) {
    AVLTree t;
    t.insert(5);
    EXPECT_TRUE(t.search(5));
    EXPECT_TRUE(t.isBalanced());
}


TEST(AvlTreeTest, Insert_ForLeftRotate) {
    AVLTree t;
    for (int i = 1; i <= 30; i++) {
        t.insert(i);
    }
    EXPECT_TRUE(t.search(30));
    EXPECT_TRUE(t.isBalanced());
}


TEST(AvlTreeTest, Insert_ForeRightRotate) {
    AVLTree t;
    for (int i = 30; i > 0; i--) {
        t.insert(i);
    }
    EXPECT_TRUE(t.search(1));
    EXPECT_TRUE(t.isBalanced());
}


TEST(AvlTreeTest, Insert_RotateRightLeft) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(32);
    t.insert(7);
    t.insert(27);
    t.insert(42);
    t.insert(37);
    t.insert(47);
    t.insert(36);
    EXPECT_TRUE(t.search(36));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Insert_RotateLeftRight) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(32);
    t.insert(17);
    t.insert(7);
    t.insert(42);
    t.insert(4);
    t.insert(9);
    t.insert(11);
    EXPECT_TRUE(t.search(11));
    EXPECT_TRUE(t.isBalanced());
}

///////////////////////
//Remove-Tests
///////////////////////


TEST(AvlTreeTest, Remove_Root) {
    AVLTree t;
    for (int i = 30; i > 0; i--) {
        t.insert(i);
    }
    t.remove(15);
    EXPECT_FALSE(t.search(15));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_NodeTwoChilds) {
    AVLTree t;
    for (int i = 30; i > 0; i--) {
        t.insert(i);
    }
    t.remove(11);
    EXPECT_FALSE(t.search(11));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_NodeOneChilds) {
    AVLTree t;
    for (int i = 26; i > 0; i--) {
        t.insert(i);
    }
    t.remove(2);
    EXPECT_FALSE(t.search(2));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_NodeNoChild) {
    AVLTree t;
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.remove(5);
    EXPECT_FALSE(t.search(5));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_NodeNotExist) {
    AVLTree t;
    t.insert(33);
    t.remove(200);
    EXPECT_FALSE(t.search(200));
    EXPECT_TRUE(t.search(33));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_RotateRightSubtree) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(32);
    t.insert(7);
    t.insert(27);
    t.insert(42);
    t.insert(37);
    t.insert(47);
    t.remove(27);
    EXPECT_FALSE(t.search(27));
    EXPECT_TRUE(t.isBalanced());
}


TEST(AvlTreeTest, Remove_RotateLeftRight) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(32);
    t.insert(17);
    t.insert(7);
    t.insert(42);
    t.insert(4);
    t.insert(9);
    t.remove(17);
    EXPECT_FALSE(t.search(17));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRightRotate) {
    AVLTree t;
    t.insert(22);
    t.insert(27);
    t.insert(12);
    t.insert(7);
    t.insert(17);
    t.remove(17);
    EXPECT_FALSE(t.search(17));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRightNoLeftChild) {
    AVLTree t;
    t.insert(22);
    t.insert(27);
    t.insert(12);
    t.insert(17);
    t.remove(17);
    EXPECT_FALSE(t.search(17));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeftNoRightChild) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(27);
    t.insert(7);
    t.insert(17);
    t.insert(24);
    t.remove(24);
    EXPECT_FALSE(t.search(24));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeaf) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(7);
    t.insert(17);
    t.remove(17);
    EXPECT_FALSE(t.search(17));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftLeaf) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(7);
    t.insert(17);
    t.remove(7);
    EXPECT_FALSE(t.search(7));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_PreviousWithOnLeftLeaf) {
    AVLTree t;
    t.insert(22);
    t.insert(12);
    t.insert(27);
    t.insert(7);
    t.insert(17);
    t.insert(24);
    t.insert(25);
    t.remove(24);
    EXPECT_FALSE(t.search(24));
    EXPECT_TRUE(t.isBalanced());
    EXPECT_TRUE(t.isBalanced());
}


TEST(AvlTreeTest, Remove_LeftRotate){
    AVLTree t;
    t.insert(10);
    t.insert(7);
    t.insert(14);
    t.insert(13);
    t.insert(12);
    t.insert(4);
    t.insert(15);
    t.insert(11);
    t.remove(4);
    EXPECT_FALSE(t.search(4));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeftRotate_UpOut){
    AVLTree t;
    t.insert(12);
    t.insert(7);
    t.insert(17);
    t.insert(14);
    t.insert(13);
    t.insert(4);
    t.insert(15);
    t.insert(16);
    t.remove(4);
    EXPECT_FALSE(t.search(4));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRightRotate_UpOut){
    AVLTree t;
    t.insert(22);
    t.insert(32);
    t.insert(15);
    t.insert(17);
    t.insert(18);
    t.insert(42);
    t.insert(11);
    t.insert(19);
    t.remove(42);
    EXPECT_FALSE(t.search(42));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_RightRotate_UpOut){
    AVLTree t;
    t.insert(22);
    t.insert(32);
    t.insert(15);
    t.insert(17);
    t.insert(18);
    t.insert(42);
    t.insert(11);
    t.remove(42);
    EXPECT_FALSE(t.search(42));
    EXPECT_TRUE(t.isBalanced());
    EXPECT_THAT(*t.preorder(), testing::ElementsAre(17, 15, 11, 22, 18, 32));
    EXPECT_THAT(*t.inorder(), testing::ElementsAre(11, 15, 17, 18, 22, 32));
    EXPECT_THAT(*t.postorder(), testing::ElementsAre(11, 15, 18, 32, 22, 17));
}

TEST(AvlTreeTest, Remove_LoopInsertLowToHigh) {
    AVLTree t;
    for (int i = 20; i > 0; i--) {
        t.insert(i);
    }
    t.remove(6);
    t.remove(18);
    t.remove(4);
    t.remove(1);
    t.remove(20);
    t.remove(12);
    t.remove(9);
    t.remove(6);
    t.remove(7);
    EXPECT_TRUE(t.isBalanced());
    EXPECT_FALSE(t.search(6));
    EXPECT_FALSE(t.search(18));
    EXPECT_FALSE(t.search(4));
    EXPECT_FALSE(t.search(1));
    EXPECT_FALSE(t.search(20));
    EXPECT_FALSE(t.search(12));
    EXPECT_FALSE(t.search(9));
    EXPECT_FALSE(t.search(6));
    EXPECT_FALSE(t.search(7));
}

TEST(AvlTreeTest, Remove_LoopInsertLowToHigh_toRemoveIsLeft) {
    AVLTree t;
    for (int i = 20; i > 0; i--) {
        t.insert(i);
    }
    t.remove(6);
    t.remove(18);
    t.remove(4);
    t.remove(1);
    t.remove(20);
    t.remove(12);
    t.remove(17);
    t.remove(14);
    t.remove(16);
    EXPECT_TRUE(t.isBalanced());
    EXPECT_FALSE(t.search(6));
    EXPECT_FALSE(t.search(18));
    EXPECT_FALSE(t.search(4));
    EXPECT_FALSE(t.search(1));
    EXPECT_FALSE(t.search(20));
    EXPECT_FALSE(t.search(12));
    EXPECT_FALSE(t.search(17));
    EXPECT_FALSE(t.search(14));
    EXPECT_FALSE(t.search(16));
}


TEST(AvlTreeTest, Remove_LoopTenToZero){
    AVLTree t;
    for (int i = 10; i > 0; i--) {
        t.insert(i);
    }
    t.remove(4);
    t.remove(2);
    t.remove(10);
    t.remove(9);
    EXPECT_FALSE(t.search(4));
    EXPECT_FALSE(t.search(2));
    EXPECT_FALSE(t.search(10));
    EXPECT_FALSE(t.search(9));
    EXPECT_TRUE(t.isBalanced());
}

TEST(AvlTreeTest, Remove_BothLeaf_RoatetLeft){
    AVLTree t;
    t.insert(10);
    t.insert(8);
    t.insert(15);
    t.insert(13);
    t.insert(17);
    t.insert(18);
    t.remove(13);
    EXPECT_FALSE(t.search(13));
    EXPECT_TRUE(t.isBalanced());
}
