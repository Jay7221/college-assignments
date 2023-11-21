#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> adj, vector<int> &path, vector<bool> &vis){
    vis[node] = true;
    for(int v : adj[node]){
        if(!vis[v]){
            dfs(v, adj, path, vis);
        }
    }
    path.push_back(node);
}
int main(){
    int n, m;
    cerr << "Enter the number of committes: \n";
    cin >> n;
    cerr << "Enter the number of dependencies: \n";
    cin >> m;
    cerr << "Enter the dependencies: \n";
    /*

        Review Board - 1
        Hospitality - 2
        Registration - 3
        Finance - 4
        Session - 5
        Approval from TEQIP coordinator - 6
        Food - 7
        Paper - 8
        Poster - 9
        Approval from director - 10
    */
    map<int, string> mp = {
        {1, "Review Board"},
        {2, "Hospitality "},
        {3, "Registration "},
        {4, "Finance "},
        {5, "Session "},
        {6, "Approval from TEQIP coordinator"},
        {7, "Food "},
        {8, "Paper "},
        {9, "Poster "},
        {10, "Approval from director"},
    };
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }
    vector<int> path;
    vector<bool> vis(n);
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i, adj, path, vis);
        }
    }
    reverse(path.begin(), path.end());
    cerr << "The order of execution is : \n";
    for(int u : path){
        cout << (u + 1) << ' ' << mp[u + 1] << '\n';
    }
    cout << '\n';
}
