#include "testAVLTree.h"
#include <memory>

using namespace std;

//// Insert-Tests
//TEST(AVLTreeTest, One_Node) {
//    AVLTree b;
//    b.insert(12213);
//    EXPECT_TRUE(b.search(12213));
//    EXPECT_FALSE(b.search(123));
//    EXPECT_FALSE(b.search(-123));
//}
//
//TEST(AVLTreeTest, Two_Nodes_Lower) {
//    AVLTree b;
//    b.insert(12213);
//    EXPECT_TRUE(b.search(12213));
//    b.insert(215);
//    EXPECT_TRUE(b.search(215));
//}
//
//TEST(AVLTreeTest, Two_Nodes_Greater) {
//    AVLTree b;
//    b.insert(12);
//    b.insert(215);
//    EXPECT_TRUE(b.search(12));
//    EXPECT_TRUE(b.search(215));
//}
//
//TEST(AVLTreeTest, Three_Nodes) {
//    AVLTree b;
//    b.insert(12213);
//    b.insert(215);
//    b.insert(123712);
//    EXPECT_TRUE(b.search(12213));
//    EXPECT_TRUE(b.search(123712));
//    EXPECT_TRUE(b.search(215));
//}
//
//TEST(AVLTreeTest, Insert_BalanceOneInsertLeft) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(7);
//    b.insert(4);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(7));
//    EXPECT_TRUE(b.search(4));
//}
//
//TEST(AVLTreeTest, Insert_BalanceMinusOneInsertRight) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(4);
//    b.insert(7);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(4));
//    EXPECT_TRUE(b.search(7));
//}
//
//TEST(AVLTreeTest, Insert_BalanceZeroToOne) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(4);
//    b.insert(7);
//    b.insert(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(4));
//    EXPECT_TRUE(b.search(7));
//    EXPECT_TRUE(b.search(8));
//}
//
//TEST(AVLTreeTest, Insert_BalanceZeroToMinnusOne) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(4);
//    b.insert(7);
//    b.insert(2);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(4));
//    EXPECT_TRUE(b.search(7));
//    EXPECT_TRUE(b.search(2));
//}
//
//TEST(AVLTreeTest, Insert_RotateRight) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(4);
//    b.insert(3);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(4));
//    EXPECT_TRUE(b.search(3));
//}
//
//TEST(AVLTreeTest, Insert_RotateLeftRight) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(3);
//    b.insert(4);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(3));
//    EXPECT_TRUE(b.search(4));
//}
//
//TEST(AVLTreeTest, Insert_RotateOnlyLeft) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(7);
//    b.insert(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(7));
//    EXPECT_TRUE(b.search(8));
//}
//
//TEST(AVLTreeTest, Insert_RotateRightLeft) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(9);
//    b.insert(6);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(9));
//    EXPECT_TRUE(b.search(6));
//}
//
////Remove Tests
//TEST(AVLTree, Remove_Root) {
//    AVLTree b;
//    b.insert(100);
//    EXPECT_TRUE(b.search(100));
//    b.remove(100);
//    EXPECT_FALSE(b.search(100));
//}
//
//TEST(AVLTree, Remove_RootLeftChild) {
//    AVLTree b;
//    b.insert(100);
//    b.insert(50);
//    EXPECT_TRUE(b.search(100));
//    EXPECT_TRUE(b.search(50));
//    b.remove(100);
//    EXPECT_TRUE(b.search(50));
//    EXPECT_FALSE(b.search(100));
//}
//
//TEST(AVLTree, Remove_RootRightChild) {
//    AVLTree b;
//    b.insert(100);
//    b.insert(200);
//    EXPECT_TRUE(b.search(100));
//    EXPECT_TRUE(b.search(200));
//    b.remove(100);
//    EXPECT_TRUE(b.search(200));
//    EXPECT_FALSE(b.search(100));
//}
//
//TEST(AVLTree, Remove_RootChild) {
//    AVLTree b;
//    b.insert(100);
//    b.insert(50);
//    b.insert(200);
//    EXPECT_TRUE(b.search(100));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(200));
//    b.remove(100);
//    EXPECT_TRUE(b.search(200));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_FALSE(b.search(100));
//}
//
//TEST(AVLTree, Remove_NodeInSubtreeWithChildrenLeft) {
//    AVLTree b;
//    b.insert(50);
//    b.insert(10);
//    b.insert(9);
//    b.insert(20);
//    b.insert(80);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(9));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(80));
//    b.remove(10);
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(9));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(80));
//    EXPECT_FALSE(b.search(10));
//}
//
//TEST(AVLTree, Remove_NodeInSubtreeWithChildrenRight) {
//    AVLTree b;
//    b.insert(50);
//    b.insert(10);
//    b.insert(80);
//    b.insert(60);
//    b.insert(100);
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(80));
//    EXPECT_TRUE(b.search(60));
//    EXPECT_TRUE(b.search(100));
//    b.remove(80);
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(60));
//    EXPECT_TRUE(b.search(100));
//    EXPECT_FALSE(b.search(80));
//}
//
//TEST(AVLTreeTest, Remove_BlanaceMinusOneRemoveLeft) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(4);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(4));
//    b.remove(4);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_FALSE(b.search(4));
//}
//
//TEST(AVLTreeTest, Remove_BlanaceOneRemoveRight) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(8));
//    b.remove(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_FALSE(b.search(8));
//}
//
//TEST(AVLTreeTest, Remove_BlanaceZeroRemoveRight) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(3);
//    b.insert(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(3));
//    EXPECT_TRUE(b.search(8));
//    b.remove(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(3));
//    EXPECT_FALSE(b.search(8));
//}
//
//TEST(AVLTreeTest, Remove_BlanaceZeroRemoveLeft) {
//    AVLTree b;
//    b.insert(5);
//    b.insert(3);
//    b.insert(8);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(3));
//    EXPECT_TRUE(b.search(8));
//    b.remove(3);
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_FALSE(b.search(3));
//}
//
//TEST(AVLTreeTest, Remove_RotateLeft) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(20);
//    b.insert(15);
//    b.insert(25);
//    b.insert(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(15));
//    EXPECT_TRUE(b.search(25));
//    EXPECT_TRUE(b.search(2));
//    b.remove(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(15));
//    EXPECT_TRUE(b.search(25));
//    EXPECT_FALSE(b.search(2));
//}
//
//
//TEST(AVLTreeTest, Remove_RotateLeftBalanceOne) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(20);
//    b.insert(25);
//    b.insert(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(25));
//    EXPECT_TRUE(b.search(2));
//    b.remove(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(25));
//    EXPECT_FALSE(b.search(2));
//}
//
//TEST(AVLTreeTest, Remove_DoubleRightLeft) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(20);
//    b.insert(15);
//    b.insert(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(15));
//    EXPECT_TRUE(b.search(2));
//    b.remove(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(15));
//    EXPECT_FALSE(b.search(2));
//}
//
//TEST(AVLTreeTest, Remove_RotateRight) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(20);
//    b.insert(8);
//    b.insert(2);
//    b.insert(9);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_TRUE(b.search(2));
//    EXPECT_TRUE(b.search(9));
//    b.remove(20);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_FALSE(b.search(20));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_TRUE(b.search(2));
//    EXPECT_TRUE(b.search(9));
//}
//
//TEST(AVLTreeTest, Remove_RotateRightBlanceMinusOne) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(20);
//    b.insert(8);
//    b.insert(2);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_TRUE(b.search(2));
//    b.remove(20);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_FALSE(b.search(20));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_TRUE(b.search(2));
//}
//
//TEST(AVLTreeTest, Remove_DoulbeRotateLeftRight) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(20);
//    b.insert(8);
//    b.insert(9);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_TRUE(b.search(9));
//    b.remove(20);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_FALSE(b.search(20));
//    EXPECT_TRUE(b.search(8));
//    EXPECT_TRUE(b.search(9));
//}
//
//TEST(AVLTreeTest, Remove_RotateLeftSecond) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(5);
//    b.insert(30);
//    b.insert(20);
//    b.insert(50);
//    b.insert(40);
//    b.insert(60);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(30));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(40));
//    EXPECT_TRUE(b.search(60));
//    b.remove(30);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_FALSE(b.search(30));
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(40));
//    EXPECT_TRUE(b.search(60));
//}
//
//TEST(AVLTreeTest, Remove_RemoveRightLeaf) {
//    AVLTree b;
//    b.insert(10);
//    b.insert(5);
//    b.insert(30);
//    b.insert(20);
//    b.insert(50);
//    b.insert(40);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(30));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(40));
//    b.remove(40);
//    EXPECT_TRUE(b.search(10));
//    EXPECT_FALSE(b.search(40));
//    EXPECT_TRUE(b.search(5));
//    EXPECT_TRUE(b.search(20));
//    EXPECT_TRUE(b.search(50));
//    EXPECT_TRUE(b.search(30));
//}

TEST(AvlTreeTest, Insert_Not_Exists) {
    AVLTree tree;
    tree.insert(2);
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Insert_Exists) {
    AVLTree tree;
    tree.insert(2);
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Search_Empty) {
    AVLTree tree;
    EXPECT_FALSE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Search_Not_Exists) {
    AVLTree tree;
    tree.insert(1);
    EXPECT_FALSE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Search_Exists) {
    AVLTree tree;
    tree.insert(1);
    EXPECT_TRUE(tree.search(1));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Search_Exists_Right) {
    AVLTree tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(1);
    tree.insert(10);
    ASSERT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Search_Exists_Left) {
    AVLTree tree;
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(1);
    ASSERT_TRUE(tree.search(1));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Insert_LeftRotateForce) {
    AVLTree tree;
    for (int i = 1; i <= 30; i++) {
        tree.insert(i);
    }
    EXPECT_TRUE(tree.search(30));
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Insert_RightRotateForce) {
    AVLTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    EXPECT_TRUE(tree.search(1));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Root) {
    AVLTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(15);
    EXPECT_FALSE(tree.search(15));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_2Childs) {
    AVLTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(11);
    EXPECT_FALSE(tree.search(11));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_1Childs) {
    AVLTree tree;
    for (int i = 26; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(2);
    EXPECT_FALSE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}



TEST(AvlTreeTest, RemoveItem0Childs) {
    AVLTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.remove(3);
    EXPECT_FALSE(tree.search(3));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, RemoveItemNotExist) {
    AVLTree tree;
    tree.insert(1);
    tree.remove(0);
    EXPECT_FALSE(tree.search(0));
    EXPECT_TRUE(tree.search(1));
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, RemoveRotateRightInner) {
    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(25);
    tree.insert(40);
    tree.insert(35);
    tree.insert(45);
    tree.remove(25);
    EXPECT_FALSE(tree.search(25));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Insert_RotateRightLeft) {
    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(25);
    tree.insert(40);
    tree.insert(35);
    tree.insert(45);
    tree.insert(34);
    EXPECT_TRUE(tree.search(34));
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Remove_RotateLeftRight) {
    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(15);
    tree.insert(5);
    tree.insert(40);
    tree.insert(2);
    tree.insert(7);
    tree.remove(15);
    EXPECT_FALSE(tree.search(15));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Insert_RotateLeftRight) {
    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(15);
    tree.insert(5);
    tree.insert(40);
    tree.insert(2);
    tree.insert(7);
    tree.insert(9);
    EXPECT_TRUE(tree.search(9));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRight) {

    AVLTree tree;
    tree.insert(20);
    tree.insert(25);
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.remove(15);
    EXPECT_FALSE(tree.search(15));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRightNoOtherChild) {

    AVLTree tree;
    tree.insert(20);
    tree.insert(25);
    tree.insert(10);
    tree.insert(15);
    tree.remove(15);
    EXPECT_FALSE(tree.search(15));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeftNoOtherChild) {

    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);
    tree.insert(22);
    tree.remove(22);
    EXPECT_FALSE(tree.search(22));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeaf) {

    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.remove(15);
    EXPECT_FALSE(tree.search(15));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftLeaf) {

    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.remove(5);
    EXPECT_FALSE(tree.search(5));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeft) {

    AVLTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);
    tree.insert(22);
    tree.insert(23);
    tree.remove(22);
    EXPECT_FALSE(tree.search(22));
    EXPECT_TRUE(tree.isBalanced());
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Rem2){
    AVLTree tree;
    for (int i = 10; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(4);
    tree.remove(2);
    tree.remove(10);
    tree.remove(9);
    EXPECT_FALSE(tree.search(4));
    EXPECT_FALSE(tree.search(2));
    EXPECT_FALSE(tree.search(10));
    EXPECT_FALSE(tree.search(9));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRotate){
    AVLTree tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(12);
    tree.insert(11);
    tree.insert(10);
    tree.insert(2);
    tree.insert(13);
    tree.insert(9);
    tree.remove(2);
    EXPECT_FALSE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeftRotate_UpOut){
    AVLTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(12);
    tree.insert(11);
    tree.insert(2);
    tree.insert(13);
    tree.insert(14);
    tree.remove(2);
    EXPECT_FALSE(tree.search(2));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRightRotate_UpOut){
    AVLTree tree;
    tree.insert(20);
    tree.insert(30);
    tree.insert(13);
    tree.insert(15);
    tree.insert(16);
    tree.insert(40);
    tree.insert(9);
    tree.insert(17);
    tree.remove(40);
    EXPECT_FALSE(tree.search(40));
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightRotate_UpOut){
    AVLTree tree;
    tree.insert(20);
    tree.insert(30);
    tree.insert(13);
    tree.insert(15);
    tree.insert(16);
    tree.insert(40);
    tree.insert(9);
    tree.remove(40);
    EXPECT_FALSE(tree.search(40));
    EXPECT_TRUE(tree.isBalanced());
    EXPECT_THAT(*tree.preorder(), testing::ElementsAre(15, 13, 9, 20, 16, 30));
    EXPECT_THAT(*tree.inorder(), testing::ElementsAre(9, 13, 15, 16, 20, 30));
    EXPECT_THAT(*tree.postorder(), testing::ElementsAre(9, 13, 16, 30, 20, 15));
}

TEST(AvlTreeTest, Rem) {
    AVLTree tree;
    for (int i = 20; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(6);
    tree.remove(18);
    tree.remove(4);
    tree.remove(1);
    tree.remove(20);
    tree.remove(12);
    tree.remove(9);
    tree.remove(6);
    tree.remove(7);
    //Fehler entsteht beim letzten remove
    EXPECT_TRUE(tree.isBalanced());
    EXPECT_FALSE(tree.search(6));
    EXPECT_FALSE(tree.search(18));
    EXPECT_FALSE(tree.search(4));
    EXPECT_FALSE(tree.search(1));
    EXPECT_FALSE(tree.search(20));
    EXPECT_FALSE(tree.search(12));
    EXPECT_FALSE(tree.search(9));
    EXPECT_FALSE(tree.search(6));
    EXPECT_FALSE(tree.search(7));
}
