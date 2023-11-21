#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cerr << "Enter the number of nodes : \n";
    cin >> n;
    cerr << "Enter the number of edges : \n";
    cin >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    const int INF = 1e9 + 7;
    vector<int> dist(n, INF);
    dist[0] = 0;

    vector<bool> open(n, true);
    int numberOpen = n;

    auto getMinOpen = [&](){
        int node = -1;
        for(int i = 0; i < n; ++i){
            if(open[i]){
                if(node == -1){
                    node = i;
                }
                if(dist[node] > dist[i]){
                    node = i;
                }
            }
        }
        return node;
    };

    int num_moves = 0;
    while((numberOpen > 0) && (num_moves < n + 1)){
        int node = getMinOpen();
        open[node] = false;
        --numberOpen;
        for(auto [nei, w] : adj[node]){
            if(dist[nei] > dist[node] + w){
                dist[nei] = dist[node] + w;
                if(!open[nei]){
                    open[nei] = true;
                    ++numberOpen;
                }
            }
        }
        ++num_moves;
    }
    for(int i = 0; i < n; ++i){
        if(open[i]){
            cout << "Negative cycle detected ...\n";
            return 0;
        }
    }
    for(int i = 0; i < n; ++i){
        cout << (char)('A' + i) << " : " << dist[i] << '\n';
    }
}
