#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class BST
{
public:
	BST();
	BST(const BST &rhs);
	~BST();
	const int  findMin() const;
	const int  findMax() const;
	bool contain(const int &x) const;
	bool isEmtpy() const;
	void printTree(ostream& out = cout) const;

	void makeEmpty();
	void insert(const int &x);
	void remove(const int &x);

	const BST& operator=(const BST &rhs);

private:
	struct BinaryTreeNode
	{
		int val;
		BinaryTreeNode *left;
		BinaryTreeNode *right;
		BinaryTreeNode() : val(0), left(NULL), right(NULL) {}
		BinaryTreeNode(const int &x) : val(x), left(NULL), right(NULL) {}
		BinaryTreeNode(const int&x, BinaryTreeNode* l, BinaryTreeNode * r) : val(x), left(l), right(r) {}
	};
	BinaryTreeNode *root;
	void insert(const int &x, BinaryTreeNode *&t) const;
	void remove(const int &x, BinaryTreeNode *&t) const;
	BinaryTreeNode *findMin(BinaryTreeNode *t) const;
	BinaryTreeNode *findMax(BinaryTreeNode *t) const;
	bool contain(const int &x, BinaryTreeNode *t) const;
	void makeEmpty(BinaryTreeNode *&t);
	void print(BinaryTreeNode *t, ostream& out) const;
	BinaryTreeNode *clone(BinaryTreeNode *t) const;
};

inline BST::BST() : root(new BinaryTreeNode())
{

}


bool BST::contain(const int &x) const
{
	return contain(x, root);
}

void BST::insert(const int &x)
{
	insert(x, root);
}
void BST::remove(const int &x)
{
	remove(x, root);
}

bool BST::contain(const int &x, BinaryTreeNode *t) const
{
	if (t == NULL) return false;
	if (x < t->val) return contain(x, t->left);
	else if (x > t->val) return contain(x, t->right);
	return true;
}

const int BST::findMin() const
{
	return root == NULL ? 0 : findMin(root)->val;
}

BST::BinaryTreeNode* BST::findMin(BinaryTreeNode* t) const
{
	if (t == NULL) return NULL;
	else if (t->left == NULL) return t;
	return findMin(t->left);
}

const int BST::findMax() const
{
	return root == NULL ? 0 : findMax(root)->val;
}

BST::BinaryTreeNode* BST::findMax(BinaryTreeNode* t) const
{
	if (t == NULL) return NULL;
	else if (t->right == NULL) return t;
	return findMin(t->right);
}


void BST::insert(const int &x, BinaryTreeNode *&t) const
{
	if (t == NULL)
		t = new BinaryTreeNode(x);
	else if (x < t->val)
		insert(x, t->left);
	else if (x > t->val)
		insert(x, t->right);
	else
		;
}

void BST::remove(const int &x, BinaryTreeNode *&t) const
{
	if (t == NULL)
		return;
	if (x < t->val)
		remove(x, t->left);
	else if (x > t->val)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL)
	{
		t->val = findMin(t->right)->val;
		remove(t->val, t->right);
	}
	else
	{
		BinaryTreeNode *oldnode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldnode;
	}

}

BST::~BST()
{
	makeEmpty();
}

void BST::makeEmpty(BinaryTreeNode* &t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

const BST& BST::operator=(const BST& rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

BST::BinaryTreeNode * BST::clone(BinaryTreeNode *t) const
{
	if (t == NULL)
		return NULL;
	return new BinaryTreeNode(t->val, clone(t->left), clone(t->right));
}



bool BST::isEmtpy() const

{
	return root == NULL;
}

void BST::makeEmpty()
{

	makeEmpty(root);
}

void BST::print(BinaryTreeNode* t, ostream& out) const
{
	if (t != NULL)
	{
		print(t->left, out);
		out << t->val << endl;
		print(t->right, out);
	}
}

void BST::printTree(ostream& out) const
{
	print(root, out);
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream input(line);
		int tmp;
		BST bst;
		while (input >> tmp)
		{
			bst.insert(tmp);
		}
		bst.printTree(cout);
	}

}
