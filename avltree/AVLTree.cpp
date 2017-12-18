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
                    AVLTree::upin(helper);
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
                    AVLTree::upin(helper);
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

void AVLTree::upin(AVLTree::Node *element) {
    if(element != nullptr && element->previous != nullptr) {
        Node *previous = element->previous;
        if(element == previous->left) {
            if(element->balance == -1 && previous->balance == -1) {
                //rotateRight();
                previous->balance = 0;
            } else if(element->balance == 1 && previous->balance == -1) {
                //rotateLeftRight();
                previous->balance = 0;
            } else if(previous->balance == 0) {
                previous->balance = -1;
                upin(previous);
            } else if(previous->balance == 1) {
                previous->balance = 0;
            }
            return;
        }
        else {
            if(element->balance == -1 && previous->balance == -1) {
                //rotateLeft();
                previous->balance = 0;
            } else if(element->balance == 1 && previous->balance == -1) {
                //rotateRightLeft();
                previous->balance = 0;
            } else if(previous->balance == 0) {
                previous->balance = 1;
                upin(previous);
            } else if(previous->balance == 1) {
                previous->balance = 0;
            }
            return;
        }
    }

}