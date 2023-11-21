#include<bits/stdc++.h>
using namespace std;
struct DSU{
    int n;
    vector<int> par;
    vector<int> rank;
    DSU(int sz){
        n = sz;
        par = vector<int>(n);
        rank = vector<int>(n);
        for(int i = 0; i < n; ++i){
            par[i] = i;
            rank[i] = 1;
        }
    }
    int get(int u){
        return par[u] = (u == par[u] ? u : get(par[u]));
    }
    void merge(int u, int v){
        u = get(u);
        v = get(v);
        if(rank[u] < rank[v]){
            swap(u, v);
        }
        par[v] = u;
        rank[u] += rank[v];
    }

};
vector<tuple<int, int, int>> krusals(int n, int m, vector<tuple<int, int, int>> &edges){
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    vector<tuple<int, int, int>> mst;
    for(auto [w, u, v] : edges){
        if(dsu.get(u) != dsu.get(v)){
            dsu.merge(u, v);
            ans += w;
            mst.push_back({w, u, v});
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
    cerr << "Edges in the MST are : " << '\n';
    for(auto [w, u, v] : mst){
        cerr << "u : " << u << ", v : " << v << ", w : " << w << '\n';
    }
}
