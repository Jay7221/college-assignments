#include<bits/stdc++.h>
using namespace std;
bool bfs(int n, int m, vector<vector<int>> adj){
    // color = 0 => not coloured
    vector<int> color(n);
    queue<int> q;
    q.push(0);
    color[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(color[v] == 0){
                color[v] = (3 - color[u]);
                q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n, m;

    cerr << "Enter the number of nodes in the graph: ";
    cin >> n;
    cerr << "Enter the number of edges in the graph: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cerr << "Enter the edges in the graph: ";
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(bfs(n, m, adj)){
        cout << "Bipartite\n";
    }
    else{
        cout << "Not Bipartite\n";
    }
}
