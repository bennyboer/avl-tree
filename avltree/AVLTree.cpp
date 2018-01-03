#include <iostream>
#include <functional>
#include <vector>
#include "AVLTree.h"

/********************************************************************
 * Tree Constructor(s) / Destructor(s)
 *******************************************************************/

AVLTree::~AVLTree() {
	// Delete root node.
	delete root;
}


/********************************************************************
 * Node constructor(s) / destructor(s)
 *******************************************************************/

AVLTree::Node::Node(const int key, Node *parent) : key(key), previous(parent) {

}

AVLTree::Node::Node(const int key,
					AVLTree::Node *left,
					AVLTree::Node *right,
					AVLTree::Node *previous,
					int p) : key(key),
							 left(left),
							 right(right),
							 previous(previous),
							 balance(p) {

}

AVLTree::Node::~Node() {
	// Delete all nodes recursively.
	delete left;
	delete right;
}


/********************************************************************
 * Node methods
 *******************************************************************/

bool AVLTree::Node::hasChildren() const {
	return left != nullptr || right != nullptr;
}

bool AVLTree::Node::isBalanced() const {
	return balance == 0;
}


/********************************************************************
 * Tree Search
 *******************************************************************/

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


/********************************************************************
 * Tree Insert
 *******************************************************************/

void AVLTree::insert(const int value) {
	if (root == nullptr) {
		// Insert root node.
		root = new Node(value, nullptr);
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
			node->left = new Node(value, node);

			// Adjust balance.
			node->balance -= 1;

			if (!node->isBalanced()) {
				upIn(node);
			}
		} else {
			insert(value, node->left);
		}
	} else if (node->key < value) {
		if (node->right == nullptr) {
			// Insert node.
			node->right = new Node(value, node);

			// Adjust balance.
			node->balance += 1;

			if (!node->isBalanced()) {
				upIn(node);
			}
		} else {
			insert(value, node->right);
		}
	}
}


/********************************************************************
 * Tree remove
 *******************************************************************/

void AVLTree::remove(const int value) {
	if (root != nullptr) {
		remove(value, root);
	}
}

void AVLTree::remove(const int value, Node *node) {
	if (node->key == value) {
		if (!node->hasChildren()) {
			removeNodeBothLeaf(node);
		} else if (node->left == nullptr && node->right != nullptr) {
			removeNodeOneLeaf(node, false);
		} else if (node->right == nullptr && node->left != nullptr) {
			removeNodeOneLeaf(node, true);
		} else {
			removeNodeNoLeaf(node);
		}
	} else if (node->key > value) {
		remove(value, node->left);
	} else if (node->key < value) {
		remove(value, node->right);
	}
}

void AVLTree::removeNodeBothLeaf(Node *toRemove) {
	if (toRemove->previous != nullptr) {
		int newBalance = toRemove->previous->balance;

		if (toRemove->previous->left == toRemove) {
			toRemove->previous->left = nullptr;

			// Modify balance of previous node.
			newBalance += 1;
		} else if (toRemove->previous->right == toRemove) {
			toRemove->previous->right = nullptr;

			// Modify balance of previous node.
			newBalance -= 1;
		}

		if (newBalance == 0) {
			toRemove->previous->balance = newBalance;
			upOut(toRemove->previous);
		} else if (newBalance == -2) {
			// Check if single rotate or double rotate
			auto previous = toRemove->previous;
			auto brotherTree = previous->left;

			if (brotherTree->right == nullptr) {
				previous = rotateRight(previous);
			} else {
				rotateLeft(brotherTree);
				previous = rotateRight(previous);
			}

			// Check if tree height changed
			if (previous->isBalanced()) {
				upOut(previous);
			}
		} else if (newBalance == 2) {
			// Check if single rotate or double rotate
			auto previous = toRemove->previous;
			auto brotherTree = previous->right;

			if (brotherTree->left == nullptr) {
				previous = rotateLeft(previous);
			} else {
				rotateRight(brotherTree);
				previous = rotateLeft(previous);
			}

			// Check if tree height changed
			if (previous->isBalanced()) {
				upOut(previous);
			}
		}
	} else {
		root = nullptr;
	}

	delete toRemove;
}

void AVLTree::removeNodeOneLeaf(Node *toRemove, bool isLeft) {
	if (toRemove->previous != nullptr) {
		if (toRemove->previous->left == toRemove) {
			toRemove->previous->left = isLeft ? toRemove->left : toRemove->right;
		} else if (toRemove->previous->right == toRemove) {
			toRemove->previous->right = isLeft ? toRemove->left : toRemove->right;
		}
	} else {
		root = isLeft ? toRemove->left : toRemove->right;
	}

	if (isLeft) {
		toRemove->left = nullptr;
	} else {
		toRemove->right = nullptr;
	}

	delete toRemove;
}

void AVLTree::removeNodeNoLeaf(Node *toRemove) {
	// Find symmetric follower.
	Node *follower = toRemove->right;
	while (follower->left != nullptr) {
		follower = follower->left;
	}

	// Cache key
	int key = follower->key;

	// Remove symmetric follower.
	remove(follower->key, follower);

	// Exchange node with follower node
	auto newNode = new Node(key, toRemove->left, toRemove->right, toRemove->previous, toRemove->balance);
	if (toRemove->previous != nullptr) {
		if (toRemove->previous->left == toRemove) {
			toRemove->previous->left = newNode;
		} else if (toRemove->previous->right == toRemove) {
			toRemove->previous->right = newNode;
		}
	} else {
		root = newNode;
	}

	toRemove->left = nullptr;
	toRemove->right = nullptr;

	delete toRemove;
}


/********************************************************************
 * Tree balance methods
 *******************************************************************/

void AVLTree::upIn(Node *node) {
	if (node != nullptr && node->previous != nullptr) {
		Node *previous = node->previous;

		if (node == previous->left) {
			// Left node tree grew by one

			if (previous->balance == -1) {
				if (node->balance == -1) {
					rotateRight(previous);
				} else {
					rotateLeft(node);
					rotateRight(previous);
				}
			} else if (previous->balance == 0) {
				previous->balance = -1;
				upIn(previous);
			} else {
				previous->balance = 0;
			}

		} else {
			// Right node tree grew by one

			if (previous->balance == 1) {
				if (node->balance == 1) {
					rotateLeft(previous);
				} else {
					rotateRight(node);
					rotateLeft(previous);
				}
			} else if (previous->balance == 0) {
				previous->balance = 1;
				upIn(previous);
			} else {
				previous->balance = 0;
			}

		}
	}
}

void AVLTree::upOut(Node *node) {
	if (node != nullptr && node->previous != nullptr) {
		auto previous = node->previous;

		// Check if is left or right successor
		if (previous->left == node) {
			// Left subtree shrank by one.

			if (previous->balance == 1) {
				// Balance would be 2 now -> rotate left
				auto siblingTree = previous->right;

				if (siblingTree->left == nullptr) {
					// Single rotate left
					previous = rotateLeft(previous);
				} else {
					rotateRight(siblingTree);
					previous = rotateLeft(previous);
				}

				upOut(previous);
			} else if (previous->balance == -1) {
				previous->balance = 0;
				upOut(previous);
			} else {
				// Balance would be 1 now -> height did not change.
				previous->balance += 1;
			}
		} else {
			// Right subtree shrank by one.

			if (previous->balance == -1) {
				// Balance would be -2 now -> rotate right
				auto siblingTree = previous->left;

				if (siblingTree->right == nullptr) {
					// Single rotate right
					previous = rotateRight(previous);
				} else {
					rotateLeft(siblingTree);
					previous = rotateRight(previous);
				}

				upOut(previous);
			} else if (previous->balance == 1) {
				previous->balance = 0;
				upOut(previous);
			} else {
				// Balance would be -1 now -> height did not change.
				previous->balance -= 1;
			}
		}
	}
}


/********************************************************************
 * Rotate methods
 *******************************************************************/

AVLTree::Node *AVLTree::rotateRight(Node *head) {
	auto previous = head->previous;
	auto left = head->left;

	// Switch position
	if (previous == nullptr) {
		root = left;
		left->previous = nullptr;
	} else {
		if (previous->left == head) {
			previous->left = left;
		} else {
			previous->right = left;
		}
		left->previous = previous;
	}

	head->left = left->right;
	left->right = head;
	head->previous = left;

	// Update balance.
	head->balance += 1;
	left->balance += 1;

	// Return new head.
	return left;
}

AVLTree::Node *AVLTree::rotateLeft(Node *head) {
	auto previous = head->previous;
	auto right = head->right;

	// Switch position
	if (previous == nullptr) {
		root = right;
		right->previous = nullptr;
	} else {
		if (previous->left == head) {
			previous->left = right;
		} else {
			previous->right = right;
		}
		right->previous = previous;
	}

	head->right = right->left;
	right->left = head;
	head->previous = right;

	// Update balance.
	head->balance -= 1;
	right->balance -= 1;

	// Return new head.
	return right;
}


/********************************************************************
 * Orders
 *******************************************************************/

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