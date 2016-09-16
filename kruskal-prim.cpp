#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class FindJoinSet
{
public:
	FindJoinSet(int n) : pre(n + 1) {
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

struct MGraph
{
	int vexnum;
	vector<vector<int>> edge;
};

struct Edge
{
	int u;
	int v;
	int w;
};

struct Greater
{
	bool operator()(const Edge &a, const Edge &b)
	{
		return a.w < b.w;
	}
};

void kruskal(MGraph &G)
{
	FindJoinSet unionset(G.vexnum);
	priority_queue<Edge, vector<Edge>, Greater()> q;
	for (int i = 0; i < G.vexnum; ++i)
	{
		for (int j = 0; j < G.vexnum; ++j)
		{
			if (G.edge[i][j] != 0 && G.edge[i][j] != INFINITY)
			{
				Edge e;
				e.u = i;
				e.v = j;
				e.w = G.edge[i][j];
				q.push(e);
			}
		}
	}
	int k = G.vexnum;
	while (k != 0)
	{
		Edge tmp = q.top();
		q.pop();
		if (unionset.join(tmp.u, tmp.v))
		{
			--k;
			cout << tmp.u << "-->" << tmp.v << endl;
		}
	}
}


int prim(vector<vector<int>>& map, vector<bool> &visit)
{
	int n = map.size() - 1;
	visit[1] = true;
	int pos = 1;
	int result = 0;
	vector<int> low(map.size() + 1);
	for (int i = 1; i < map.size(); ++i)
		if (i != pos) low[i] = map[pos][i];
	for (int i = 1; i < map.size() - 1; ++i)
	{
		int min = INFINITY;
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j] == false && low[j] < min)
			{
				min = low[j];
				pos = j;
			}
		}
		visit[pos] = true;
		result += min;
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j] == false && map[pos][j] < low[j])
			{
				low[j] = map[pos][j];
			}
		}
	}
}