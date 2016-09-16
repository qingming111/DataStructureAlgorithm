
#include<vector>
#include<iostream>
using namespace std;

class UnionSet
{
public:
	UnionSet(int n) : pre(n + 1) {
		for (int i = 1; i <= n; ++i)
			pre[i] = i;
	}
	int find(int x)
	{
		int r = x;
		while (pre[r] != r)
			r = pre[r];
		int i = x, j;
		while (pre[i] != r)
		{
			j = pre[i];
			pre[i] = r;
			i = j;
		}
		return r;
	}
	int join(int x, int y)
	{
		int fx = find(x);
		int fy = find(y);
		if (fx != fy)
		{
			pre[fx] = fy;
			return 1;
		}
		return 0;
	}
private:
	vector<int> pre;
};