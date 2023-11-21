#include<bits/stdc++.h>
using namespace std;
#define t3 tuple<int, int, int>
vector<tuple<int, int, int>> krusals(int n, int m, vector<tuple<int, int, int>> &edges){
    vector<vector<pair<int, int>>> adj(n);
    for(auto [w, u, v] : edges){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<t3, vector<t3>, greater<t3>> pq;
    vector<bool> vis(n);
    vis[0] = true;
    for(auto [v, w] : adj[0]){
        pq.push({w, v, 0});
    }
    vector<tuple<int, int, int>> mst;
    while(!pq.empty()){
        int u, p, w;
        tie(w, u, p) = pq.top();
        pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = true;
        mst.push_back({w, u, p});
        for(auto [v, w] : adj[u]){
            pq.push({w, v, u});
        }
    }
    return mst;
}
int main(){
    int n, m;
    cerr << "Enter the number of nodes : " << '\n';
    cin >> n;
    cerr << "Enter the number of edges : " << '\n';
    cin >> m;
    cerr << "Enter the edges : " << '\n';
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({w, u, v});
    }
    vector<tuple<int, int, int>> mst = krusals(n, m, edges);
    int ans = 0;
    for(auto [w, u, v] : mst){
        ans += w;
    }
    cerr << "Cost of MST is : " << ans << '\n';
    cerr << "Number of edges are : " << mst.size() << '\n';
    cerr << "Edges in the MST are : " << '\n';
    for(auto [w, u, v] : mst){
        ++u, ++v;
        cerr << "u : " << u << ", v : " << v << ", w : " << w << '\n';
    }
}
