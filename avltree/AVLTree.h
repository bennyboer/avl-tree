#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

class AVLTree {
private:
	struct Node {
		const int key;
		Node *left = nullptr;
		Node *right = nullptr;
		Node *previous = nullptr;
		int balance = 0;

		Node(const int, Node *parent);

		Node(const int, Node *, Node *, Node *, int);

		~Node();

		bool hasChildren() const;

		bool isBalanced() const;

        bool checkBalance() const;

		std::vector<int> *preorder() const;  // (Hauptreihenfolge)
		std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
		std::vector<int> *postorder() const; // (Nebenreihenfolge)

	};

	Node *root = nullptr;

	void upIn(Node *);

	void upOut(Node *);

	Node *rotateRight(Node *);

	Node *rotateLeft(Node *);

	bool search(const int value, const Node *node) const;

	void insert(const int value, Node *node);

	void remove(const int value, Node *node);

	void removeNodeBothLeaf(Node *toRemove);
	void removeNodeOneLeaf(Node *toRemove, bool isLeft);
	void removeNodeNoLeaf(Node *toRemove);

    bool isBalanced_rec(Node *node) const;



public:
	~AVLTree();

	bool search(const int value) const;

	void insert(const int value);

	void remove(const int value);

	bool isBalanced() const;

	std::vector<int> *preorder() const;  // (Hauptreihenfolge)
	std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
	std::vector<int> *postorder() const; // (Nebenreihenfolge)

	friend std::ostream &operator<<(std::ostream &, const AVLTree &);

};

#endif //AVLTREE_AVLTREE_H
