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
	};

	Node *root = nullptr;

public:
	~AVLTree();

	bool search(const int value) const;

	void insert(const int value);

	void remove(const int value);
};

#endif //AVLTREE_AVLTREE_H
