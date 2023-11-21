#include<bits/stdc++.h>
using namespace std;
struct DSU{
    int n;
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        this -> n = n;
        parent = vector<int>(n);
        rank = vector<int>(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int get_par(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = get_par(parent[u]);
    }
    void merge(int u, int v){
        parent[v] = u;
    }

};
struct Job{
    string id;
    int deadline;
    int profit;
};
int compare(const Job a, const Job b){
    return (b.profit < a.profit);
}
int main(){
    int n;
    cerr << "Enter the number of jobs : " << endl;
    cin >> n;
    vector<Job> jobs(n);
    cerr << "Enter job ids : " << endl;
    for(Job &j : jobs){
        cin >> j.id;
    }
    cerr << "Enter job deadlines: " << endl;
    for(Job &j : jobs){
        cin >> j.deadline;
    }
    cerr << "Enter job profits: " << endl;
    for(Job &j : jobs){
        cin >> j.profit;
    }
    sort(jobs.begin(), jobs.end(), compare);
    DSU dsu(n + 1);
    vector<string> result(n + 1);
    vector<bool> occupied(n + 1, false);
    for(Job &j : jobs){
        int slot = dsu.get_par(j.deadline);
        if(slot != 0){
            occupied[slot] = true;
            result[slot] = j.id;
            dsu.merge(slot - 1, slot);
        }
    }
    for(int slot = 1; slot <= n; ++slot){
        if(occupied[slot]){
            cout << result[slot] << ' ';
        }
    }
    cout << endl;
    return 0;
}
