#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void dfs(int u, int n, vector<vector<int>> &graph)
{
    vector<bool> vis(n + 1);
    stack<int> st;
    vis[u] = true;
    st.push(u);
    while(st.size())
    {
        int v = st.top();
        st.pop();
        cout << v << ' ';
        for(int child : graph[v])
        {
            if(!vis[child])
            {
                vis[child] = true;
                st.push(child);
            }
        }
    }
}
void bfs(int u, int n, vector<vector<int>> &graph)
{
    vector<bool> vis(n + 1);
    queue<int> st;
    vis[u] = true;
    st.push(u);
    while(st.size())
    {
        int v = st.front();
        st.pop();
        cout << v << ' ';
        for(int child : graph[v])
        {
            if(!vis[child])
            {
                vis[child] = true;
                st.push(child);
            }
        }
    }
}
int main()
{
    cout << "Enter number of nodes in Graph :";
    int n, m;
    cin >> n;
    cout << "Enter number of edges in Graph :";
    cin >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; ++i)
    {
        cout << "Enter edge :";
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "BFS of graph is : ";
    bfs(1, n, graph);
    cout << "\n DFS of graph is : ";
    dfs(1, n, graph);
    return 0;
}