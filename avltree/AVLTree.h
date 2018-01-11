#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

/**
 * AVL Tree.
 * @authors Benjamin Eder, Max Sachmarn
 */
class AVLTree {
private:

	/**
	 * Node of a AVL Tree.
	 */
	struct Node {

		/**
		 * Key of a node used to identify nodes.
		 */
		const int key;

		/**
		 * Left successor.
		 */
		Node *left = nullptr;

		/**
		 * Right successor.
		 */
		Node *right = nullptr;

		/**
		 * Nodes predecessor node.
		 */
		Node *previous = nullptr;

		/**
		 * Balance of the node (Range: [-1, 1]).
		 */
		int balance = 0;

		/**
		 * Create node with key and parent node.
		 * @param parent node
		 */
		Node(int key, Node *parent);

		/**
		 * Create node with key, left and right successor, predecessor and balance.
		 * @param key of the node
		 * @param left successor of the node
		 * @param right successor of the node
		 * @param previous predecessor of this node
		 * @param balance of the node (Range [-1, 1])
		 */
		Node(int key, Node *left, Node *right, Node *previous, int balance);

		/**
		 * Node destructor.
		 */
		~Node();

		/**
		 * Check if the node has children.
		 * @return whether the node has children
		 */
		bool hasChildren() const;

		/**
		 * Check if the node is balanced (balance = 0).
		 * @return whether the node is balanced
		 */
		bool isBalanced() const;

		/**
		 * Check balance of the node.
		 * @return whether the node and children are balanced
		 */
		bool checkBalance() const;

		/**
		 * Get vector in preorder.
		 * @return vector in preorder
		 */
		std::vector<int> *preorder() const;

		/**
		 * Get vector in order.
		 * @return vector in order
		 */
		std::vector<int> *inorder() const;

		/**
		 * Get vector in postorder.
		 * @return vector in postorder
		 */
		std::vector<int> *postorder() const;

	};

	/**
	 * Root of the tree.
	 */
	Node *root = nullptr;

	/**
	 * Up in routine adjusting AVL Balance during inserts.
	 * @param node to adjust balance of predecessors
	 */
	void upIn(Node *node);

	/**
	 * Up out routine adjusting AVL Balance during removals.
	 * @param node to adjust balance of predecessors
	 */
	void upOut(Node *node);

	/**
	 * Rotate right around passed node.
	 * @param node to rotate around
	 * @return node at the position of the passed node
	 */
	Node *rotateRight(Node *node);

	/**
	 * Rotate left around passed node.
	 * @param node to rotate around
	 * @return node at the position of the passed node
	 */
	Node *rotateLeft(Node *);

	/**
	 * Search node with the passed value.
	 * @param value to search for
	 * @param node to search value in
	 * @return whether the node has been found
	 */
	bool search(const int value, const Node *node) const;

	/**
	 * Insert node under the passed node with the passed value.
	 * @param value to insert
	 * @param node to insert value under
	 */
	void insert(const int value, Node *node);

	/**
	 * Remove node with the passed value.
	 * @param value to remove node with
	 * @param node to remove under
	 */
	void remove(const int value, Node *node);

	/**
	 * Remove node which has no children.
	 * @param toRemove node to remove
	 */
	void removeNodeBothLeaf(Node *toRemove);

	/**
	 * Remove node which has one leaf and ond inner node as children.
	 * @param toRemove node to remove
	 * @param isLeft whether left node is inner node
	 */
	void removeNodeOneLeaf(Node *toRemove, bool isLeft);

	/**
	 * Remove node which has no leaf but two inner nodes as children.
	 * @param toRemove node to remove
	 */
	void removeNodeNoLeaf(Node *toRemove);

	bool isBalanced_rec(Node *node) const;

public:

	/**
	 * AVL Tree destructor.
	 */
	~AVLTree();

	/**
	 * Search value in tree nodes.
	 * @param value to search for
	 * @return whether the value has been found
	 */
	bool search(const int value) const;

	/**
	 * Insert value in tree.
	 * @param value to insert
	 */
	void insert(const int value);

	/**
	 * Remove value in tree.
	 * @param value to remove
	 */
	void remove(const int value);

	/**
	 * Check whether the tree is balanced.
	 * @return whether the tree is balanced
	 */
	bool isBalanced() const;

	/**
	 * Get the tree in preorder.
	 * @return the tree in preorder
	 */
	std::vector<int> *preorder() const;

	/**
	 * Get the tree in inorder.
	 * @return the tree in inorder
	 */
	std::vector<int> *inorder() const;

	/**
	 * Get the tree in postorder.
	 * @return the tree in postorder
	 */
	std::vector<int> *postorder() const;

	friend std::ostream &operator<<(std::ostream &, const AVLTree &);

};

#endif //AVLTREE_AVLTREE_H
