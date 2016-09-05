// priority_queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<stdexcept>
#include<climits>
using namespace std;

class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100);
	explicit BinaryHeap(const vector<int> &items);
	bool isEmpty() const;
	const int& findMin() const;
	void insert(const int &x);
	void deleteMin();void deleteMin(int& minitem);
	
	//void makeEmpty();
private:
	int currentsize;
	vector<int> array;
	void builHeap();
	void percolateDown(int hole);
};

BinaryHeap::BinaryHeap(int capacity) : currentsize(0)
{
	array.resize(capacity);
	array[0] = INT_MIN;
}

void BinaryHeap::builHeap()
{
	for (int i = currentsize / 2; i > 0; --i)
		percolateDown(i);
}

BinaryHeap::BinaryHeap(const vector<int> &items) : array(items.size() + 10), currentsize(items.size())
{
	for (int i = 0; i < items.size(); ++i)
		array[i + 1] = items[i];
	builHeap();
}


void BinaryHeap::insert(const int &x)
{
	if (currentsize == array.size() - 1)
		array.resize(array.size() * 2);
	int hole = ++currentsize;
	for (; hole > 1 && x < array[hole / 2]; hole /= 2)
		array[hole] = array[hole / 2];
	array[hole] = x;
}

void BinaryHeap::deleteMin()
{
	if (isEmpty())
		throw new exception("underflow");
	array[1] = array[currentsize--];
	percolateDown(1);
}


void BinaryHeap::percolateDown(int hole)
{
	int tmp = array[hole];
	int child;
	for (; hole * 2 <= currentsize; hole = child)
	{
		child = hole * 2;
		if (child != currentsize && array[child + 1] < array[child])
			++child;
		if (array[child] < tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}

void BinaryHeap::deleteMin(int &x)
{
	if (isEmpty())
		throw new exception("underoverflow");
	x = array[1];
	array[1] = array[currentsize--];
	percolateDown(1);
}

bool BinaryHeap::isEmpty() const
{
	return currentsize < 1;
}

const int& BinaryHeap::findMin() const
{
	if (isEmpty())
		throw new exception("there is no extra data");
	return array[1];
	
}




int main()
{
    return 0;
}

