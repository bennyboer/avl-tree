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
	return search(value, root);
}

bool AVLTree::search(const int value, const Node *node) const {
	if (node == nullptr) {
		return false;
	}

	if (node->key == value) {
		return true;
	} else if (node->key > value) {
		return search(value, node->left);
	} else if (node->key < value) {
		return search(value, node->right);
	}
}

void AVLTree::insert(const int value) {
	if (root == nullptr) {
		// Insert root node.
		root = new Node(value);
	}

	insert(value, root);
}

void AVLTree::insert(const int value, Node *node) {
	if (node->key == value) {
		return;
	}

	if (node->key > value) {
		if (node->left == nullptr) {
			// Insert node.
			node->left = new Node(value);

			// Adjust balance.
			node->balance -= 1;

			if (node->isUnbalanced()) {
				upin(node);
			}
		} else {
			insert(value, node->left);
		}
	} else if (node->key < value) {
		if (node->right == nullptr) {
			// Insert node.
			node->right = new Node(value);

			// Adjust balance.
			node->balance += 1;

			if (node->isUnbalanced()) {
				upin(node);
			}
		} else {
			insert(value, node->right);
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

AVLTree::Node::Node(const int key, AVLTree::Node *left, AVLTree::Node *right, AVLTree::Node *previous, int p) : key(
		key),
																												left(left),
																												right(right),
																												previous(
																														previous),
																												balance(p) {
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

bool AVLTree::Node::isUnbalanced() const {
	return balance != 0;
}

void AVLTree::upin(AVLTree::Node *element) {
	if (element != nullptr && element->previous != nullptr) {
		Node *previous = element->previous;
		if (element == previous->left) {
			if (element->balance == -1 && previous->balance == -1) {
				rotateRight(previous);
			} else if (element->balance == 1 && previous->balance == -1) {
				//rotateLeftRight();
			} else if (previous->balance == 0) {
				previous->balance = -1;
				upin(previous);
			} else if (previous->balance == 1) {
				previous->balance = 0;
			}
			return;
		} else {
			if (element->balance == -1 && previous->balance == -1) {
				//rotateLeft();
			} else if (element->balance == 1 && previous->balance == -1) {
				//rotateRightLeft();
			} else if (previous->balance == 0) {
				previous->balance = 1;
				upin(previous);
			} else if (previous->balance == 1) {
				previous->balance = 0;
			}
			return;
		}
	}
}

void AVLTree::rotateRight(Node *head) {
	Node *headPrev = head->previous;
	Node *element = head->left;
	Node *insertRight = element->right;

	element->previous = headPrev;
	head->left = insertRight;
	element->right = head;
	head->previous = element;
	head->balance = 0;
	element->balance = 0;
	if (headPrev->key < head->key) {
		headPrev->right = element;
	} else if (headPrev->key > head->key) {
		headPrev->left = element;
	}
}

void AVLTree::rotateLeft(Node *) {

}

void AVLTree::rotateLeftRight(Node *) {

}

void AVLTree::rotateRightLeft(Node *) {

}