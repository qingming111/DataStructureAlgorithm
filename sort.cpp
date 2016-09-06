// sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void insertsort1(vector<int> &nums)
{
	if (nums.size() <= 1)
		return;
	for (int i = 1; i < nums.size(); ++i)
	{
		int tmp = nums[i];
		int j = i;
		for ( ; j >= 1 && tmp < nums[j - 1]; --j)
			nums[j] = nums[j - 1];
		nums[j] = tmp;
	}
}

void insert_binary_sort(vector<int> &nums)
{
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] < nums[i - 1])
		{
			int tmp = nums[i];
			int low = 0, high = i - 1, mid;
			while (low <= high)
			{
				mid = (low + high) >> 1;
				if (tmp < nums[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			nums[low] = tmp;
			for (int j = i; j > low; --j)
				nums[j] = nums[j - 1];
		}
	}
}


void bubblesort2(vector<int>& nums)
{
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		bool exchange = false;
		for (int j = nums.size() - 1; j > i; --j)
		{
			if (nums[j] < nums[j - 1])
			{
				swap(nums[j], nums[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)
			return;
	}
}

void bubblesort1(vector<int> &nums)
{
	if (nums.size() <= 1)
		return;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i; j < nums.size(); ++j)
		{
			if (nums[i] > nums[j]) swap(nums[i], nums[j]);
		}
	}
}


void quicksort(int l, int r, vector<int>& nums)
{
	if (l < r)
	{
		int p = l;
		int partion = nums[l];
		for (int i = l + 1; i <= r; ++i)
		{
			if(nums[i] < partion)
			{
				++p;
				if (p != i) swap(nums[i], nums[p]);
			}
		}
		nums[l] = nums[p];
		nums[p] = partion;
		quicksort(l, p - 1, nums);
		quicksort(p + 1, r, nums);
	}
}

void shellsort(vector<int> &nums)
{
	for (int gap = nums.size() / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < nums.size(); ++i)
		{
			int temp = nums[i];
			int j;
			for (j = i; j >= gap && temp < nums[j - gap]; j -= gap)
			{
				nums[j] = nums[j - gap];
			}
			nums[j] = temp;
		}
	}
}

void merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> tmp(nums);
	int pa = left, pb = mid + 1;
	int index = left;
	while (pa <= mid && pb <= right)
	{
		if (tmp[pa] < tmp[pb])
		{
			nums[index++] = tmp[pa++];
		}
		else
		{
			nums[index++] = tmp[pb++];
		}
	}
	while (pa <= mid)
		nums[index++] = tmp[pa++];
	while (pb <= right)
		nums[index++] = tmp[pb++];

}

void mergesort(vector<int>&nums, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) >> 1;
		mergesort(nums, left, mid);
		mergesort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

//二叉堆的数据结构

void insert(vector<int>&nums, int x)
{
	int tmp = x;
	nums.push_back(x);
	int i = nums.size() - 1;
	for (; i > 0 && tmp < nums[(i - 1) / 2]; i /= 2)
		nums[i] = nums[(i - 1) / 2];
	nums[i] = tmp;
}

void deletemin(vector<int>&nums)
{
	swap(nums[0], nums[nums.size() - 1]);
	percolate(nums, 0);
}
void percolate(vector<int>&nums, int i)
{
	int tmp = nums[i];
	int child;
	for (; 2 * i + 1 < nums.size(); i = child)
	{
		child = 2 * i + 1;
		if (child < nums.size() - 1 && nums[child + 1] < nums[child])
			child++;
		if (nums[child] < tmp)
			nums[i] = nums[child];
		else
			break;
	}
	nums[i] = tmp;

}

void heapsort(vector<int>&nums)
{
	vector<int> vec;
	for (int i = 0; i < nums.size(); ++i)
	{
		insert(vec, nums[i]);
	}
	swap(vec, nums);
}
