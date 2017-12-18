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

		Node(const int);

		Node(const int, Node *, Node *, Node *, int);

		~Node();

		bool hasChildren() const;
		bool isUnbalanced() const;
	};

	Node *root = nullptr;

    void upin(Node *);

    void rotateRight(Node *);

    void rotateLeft(Node *);

    void rotateLeftRight(Node *);

    void rotateRightLeft(Node *);

	bool search(const int value, const Node *node) const;

	void insert(const int value, Node *node);

public:
	~AVLTree();

	bool search(const int value) const;

	void insert(const int value);

	void remove(const int value);

};

#endif //AVLTREE_AVLTREE_H
