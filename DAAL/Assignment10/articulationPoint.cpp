#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> adj, int n, vector<int> &vis, int i, int cur){
    vis[cur] = 1;
    for(int x : adj[cur]){
        if(x != i){
            if(!vis[x]){
                dfs(adj, n, vis, i, x);
            }
        }
    }
}
void findArticulationPoints(vector<vector<int>> adj, int n){
    cerr << "Articulation points are : \n";
    for(int i = 1; i <= n; ++i){
        int components = 0;
        vector<int> vis(n + 1, 0);
        for(int j = 1; j <= n; ++j){
            if(j != i){
                if(!vis[j]){
                    ++components;
                    dfs(adj, n, vis, i, j);
                }
            }
        }
        if(components > 1){
            cout << i << '\n';
        }
    }
}
int main(){
    int n, m;
    cerr << "Enter the number of nodes : \n";
    cin >> n;
    cerr << "Enter the number of edges : \n";
    cin >> m;

    vector<vector<int>> adj(n + 1);
    cerr << "Enter the edges : \n";
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findArticulationPoints(adj, n);

}
