#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cerr << "Enter the number of nodes : \n";
    cin >> n;
    cerr << "Enter the number of edges : \n";
    cin >> m;
    cerr << "Enter the edges in the format u v w: \n";
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
    }
    const int INF = 1e9 + 7;
    vector<int> dist(n, INF);
    dist[0] = 0;
    vector<int> open, closed;
    for(int i = 0; i < n; ++i){
        open.push_back(i);
    }
    auto cmp = [&](int i, int j){
        return (dist[i] > dist[j]);
    };
    vector<int> prev(n, -1), prevCost(n);
    while(!open.empty()){
        sort(open.begin(), open.end(), cmp);
        int node = open.back();
        open.pop_back();
        for(auto [neighbour, w]: adj[node]){
            if(dist[neighbour] > dist[node] + w){
                dist[neighbour] = dist[node] + w;
                prev[neighbour] = node;
                prevCost[neighbour] = w;
                cerr << node << " -> " << neighbour << " : " << dist[neighbour] << endl;
            }
        }
    }
    cerr << "The min cost for each node is : \n";
    for(int i = 0; i < n; ++i){
        cout << (i + 1) << " : " << dist[i] << '\n';
    }
    for(int i = 0; i < n; ++i){
        cout << "Path : ";
        int cur = i;
        while(cur != -1){
            cout << (cur + 1) << ' ';
            cout << (cur + 1) << ' ';
            if(prev[cur] != -1){
                cout << prevCost[cur] << ' ';
            }
            cur = prev[cur];
        }
        cout << '\n';
    }
}
