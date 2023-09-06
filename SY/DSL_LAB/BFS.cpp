#include<bits/stdc++.h>
using namespace std;
void bfs(int u, vector<vector<int>> &graph)
{
	vector<bool> vis(n, false);
	queue<int> q;
	while(q.size())
	{
		int u = q.front();
		q.pop();
	}
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	bfs(0, graph);
	return 0;
}
