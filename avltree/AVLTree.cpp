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
	return false;
}

void AVLTree::insert(const int value) {

}

void AVLTree::remove(const int value) {

}

/*
 * NODE CONSTRUCTORS AND DESTRUCTOR
 */
AVLTree::Node::Node(const int key) : key(key) {

}

AVLTree::Node::Node(const int key, AVLTree::Node *left, AVLTree::Node *right) : key(key), left(left), right(right) {

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
