#include <iostream>
#include <functional>
#include <vector>
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
				upIn(node);
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
				upIn(node);
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

void AVLTree::upIn(AVLTree::Node *element) {
	if (element != nullptr && element->previous != nullptr) {
		Node *previous = element->previous;

		if (element == previous->left) {
			// Left node tree grew by one

			if (element->balance == -1 && previous->balance == -1) {
				rotateRight(previous);
			} else if (element->balance == 1 && previous->balance == -1) {
				//rotateLeftRight();
			} else if (previous->balance == 0) {
				previous->balance = -1;
				upIn(previous);
			} else if (previous->balance == 1) {
				previous->balance = 0;
			}
		} else {
			// Right node tree grew by one

			if (element->balance == -1 && previous->balance == -1) {
				//rotateLeft();
			} else if (element->balance == 1 && previous->balance == -1) {
				//rotateRightLeft();
			} else if (previous->balance == 0) {
				previous->balance = 1;
				upIn(previous);
			} else if (previous->balance == 1) {
				previous->balance = 0;
			}
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

std::vector<int> *AVLTree::preorder() const {
	if (root == nullptr)
		return nullptr;
	return root->preorder();
}

std::vector<int> *AVLTree::Node::preorder() const {
	auto vec = new std::vector<int>();
	// Wurzel in vec
	vec->push_back(key);
	// linken Nachfolger in vec
	if (left != nullptr) {
		auto left_vec = left->preorder();
		vec->insert(vec->end(), left_vec->begin(), left_vec->end());
	}
	// rechten Nachfolger in vec
	if (right != nullptr) {
		auto right_vec = right->preorder();
		vec->insert(vec->end(), right_vec->begin(), right_vec->end());
	}
	return vec;
}

std::vector<int> *AVLTree::inorder() const {
	if (root == nullptr)
		return nullptr;
	return root->inorder();
}

std::vector<int> *AVLTree::Node::inorder() const {
	auto vec = new std::vector<int>();
	// linken Nachfolger in vec
	if (left != nullptr) {
		auto left_vec = left->inorder();
		vec->insert(vec->end(), left_vec->begin(), left_vec->end());
	}
	// Wurzel in vec
	vec->push_back(key);
	// rechten Nachfolger in vec
	if (right != nullptr) {
		auto right_vec = right->inorder();
		vec->insert(vec->end(), right_vec->begin(), right_vec->end());
	}
	return vec;
}

std::vector<int> *AVLTree::postorder() const {
	if (root == nullptr)
		return nullptr;
	return root->postorder();
}

std::vector<int> *AVLTree::Node::postorder() const {
	auto vec = new std::vector<int>();
	// linken Nachfolger in vec
	if (left != nullptr) {
		auto left_vec = left->postorder();
		vec->insert(vec->end(), left_vec->begin(), left_vec->end());
	}
	// rechten Nachfolger in vec
	if (right != nullptr) {
		auto right_vec = right->postorder();
		vec->insert(vec->end(), right_vec->begin(), right_vec->end());
	}
	// Wurzel in vec
	vec->push_back(key);
	return vec;
}

/********************************************************************
 * operator<<
 *******************************************************************/
std::ostream &operator<<(std::ostream &os, const AVLTree &tree) {
	std::function<void(std::ostream &, const int, const AVLTree::Node *node, const std::string)> printToOs
			= [&](std::ostream &os, const int value, const AVLTree::Node *node, const std::string l) {
				static int nullcount = 0;

				if (node == nullptr) {
					os << "    null" << nullcount << "[shape=point];" << std::endl;
					os << "    " << value << " -> null" << nullcount
					   << " [label=\"" << l << "\"];" << std::endl;
					nullcount++;
				} else {
					os << "    " << value << " -> " << node->key
					   << " [label=\"" << l << "\"];" << std::endl;

					printToOs(os, node->key, node->left, "l");
					printToOs(os, node->key, node->right, "r");
				}
			};
	os << "digraph tree {" << std::endl;
	if (tree.root == nullptr) {
		os << "    null " << "[shape=point];" << std::endl;
	} else {
		printToOs(os, tree.root->key, tree.root->left, "l");
		printToOs(os, tree.root->key, tree.root->right, "r");
	}
	os << "}" << std::endl;
	return os;
}