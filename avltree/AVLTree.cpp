#include <iostream>
#include "AVLTree.h"

/*
 * TREE CONSTRUCTORS AND DESTRUCTOR
 */
AVLTree::~AVLTree() {
	// Delete root node.
	delete root;
}

/*
 * TREE METHODS
 */

bool AVLTree::search(const int value) const {
    Node* helper = root;
    while(helper != nullptr) {
        if(helper->key == value) {
            return true;
        }
        if (value > helper->key) {
            helper = helper->right;
        }
        else {
            if (helper->left != nullptr) {
        }
            helper = helper->left;
        }
    }
    return false;
}

void AVLTree::insert(const int value) {
    if(search(value)) {
        return;
    }
    else if (root == nullptr) {
        root = new Node(value);
    }
    else {
        auto helper = root;
        auto helperV = helper->key;
        while(true) {
            if(value > helperV) {
                if (helper->right == nullptr) {
                    helper->right = new Node(value);
                    helper->balance -= 1;
                    if(helper->balance == -2) {
                        //rotation
                    }
                    //call upin here
                    return;
                }
                else {
                    helper = helper->left;
                    helperV = helper->key;
                }
            }
            else {
                if (helper->left == nullptr) {
                    Node *tmp = new Node(value, nullptr, nullptr, helper, 0);
                    helper->left = tmp;
                    helper->balance += 1;
                    if(helper->balance == 2) {
                        //double rotation
                    }
                    //call upin
                    return;
                }
                else {
                    helper = helper->right;
                    helperV = helper->key;
                }
            }
        }

    }
}

void AVLTree::remove(const int value) {

}

/*
 * NODE CONSTRUCTORS AND DESTRUCTOR
 */
AVLTree::Node::Node(const int key) : key(key) {

}

AVLTree::Node::Node(const int key, AVLTree::Node *left, AVLTree::Node *right, AVLTree::Node *previous, int p) : key(key), left(left), right(right),
previous(previous), balance(p) {

}

AVLTree::Node::~Node() {
	// Delete all nodes recursively.
	delete left;
	delete right;
}

/*
 * NODE METHODS
 */

bool AVLTree::Node::hasChildren() const {
	return left != nullptr || right != nullptr;
}
