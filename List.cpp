
//list
//todo: size, remove 

#include "stdafx.h"
#include<iostream>

using namespace std;


struct ListNode
{
	int value;
	ListNode* next;
	ListNode(int x) : value(x), next(NULL) {}
};

struct List
{
	friend void print(ostream& os, List* L);
public:
	List() : head(new ListNode(0)), tail(NULL) {}
	~List();
	void insertHead(int x);
	void insertTail(int x);
private:
	ListNode* head;
	ListNode* tail;
};

void List::insertHead(int x)
{
	ListNode* newp = new ListNode(x);
	newp->next = head->next;
	head->next = newp;
	if (tail == NULL)
		tail = newp;
}

List::~List()
{
	ListNode* tmp = head->next;
	if (tmp != NULL)
	{
		ListNode* t = tmp->next;
		delete tmp;
		tmp = t;
	}
	delete head;
}

void print(ostream& os, List* L)
{
	if (L->head->next == NULL)
	{
		os << "the list is empty" << endl;
	}
	ListNode* tmp = L->head->next;
	while (tmp != NULL)
	{
		os << tmp->value << " ";
		tmp = tmp->next;
	}
	os << endl;
}

void List::insertTail(int x)
{
	ListNode* newp = new ListNode(x);
	if (tail == NULL)
	{
		tail = newp;
		head->next = newp;
		return;
	}
	tail->next = newp;
	tail = newp;
	if (head->next == NULL)
		head->next = tail;
}

int main(int argc, char* argv)
{
	List *L = new List();
	L->insertTail(4);
	L->insertHead(1);
	L->insertHead(2);
	L->insertHead(3);
	L->insertTail(4);
	L->insertTail(5);
	L->insertHead(6);
	print(cout, L);
	delete L;
	system("pause");
	return 0;
}