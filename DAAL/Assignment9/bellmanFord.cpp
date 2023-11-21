#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cerr << "Enter the number of node : ";
    cin >> n;
    cerr << "Enter the number of edges: ";
    cin >> m;
    cerr << "Enter the edges in the format u v w :";

    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, w});
    }

    const int INF = 1e9 + 7;

    vector<int> dist(n, INF);
    int source;
    cerr << "Enter the source vertex : ";
    cin >> source;
    --source;
    dist[source] = 0;

    auto relax = [&](){
        bool flag = false;
        vector<int> prev = dist;
        for(auto [u, v, w] : edges){
            if(prev[u] + w < dist[v]){
                dist[v] = prev[u] + w;
                flag = true;
            }
        }
        return flag;
    };
    cout << "Relaxation " << 0 << endl;
    for(int i = 0; i < n; ++i){
        cout << (i + 1) << " : " << dist[i] << endl;
    }

    for(int i = 0; i < n - 1; ++i){
        relax();
        cout << "Relaxation " << (i + 1) << endl;
        for(int i = 0; i < n; ++i){
            cout << (i + 1) << " : " << dist[i] << endl;
        }
    }
    if(relax()){
        cout << "The given graph has a negative weight cycle!";
    }
    else{
        cout << "The minimum distance of all nodes from the source are : " << endl;
        for(int i = 0; i < n; ++i){
            cout << (i + 1) << " : " << dist[i] << endl;
        }
    }
}
