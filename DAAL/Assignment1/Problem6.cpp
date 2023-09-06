#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> getMaxTower(int h[], int w[], int n){
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        v[i] = {h[i], w[i]};
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> tower;
    auto cmp = [](pair<int, int> p, pair<int, int> q){
        return (p.second < q.second);
    };
    for(pair<int, int> cur : v){
        if((tower.empty()) || (tower.back().second < cur.second)){
            tower.push_back(cur);
        }
        else{
            int ind = lower_bound(tower.begin(), tower.end(), cur, cmp) - tower.begin();
            tower[ind] = cur;
        }
    }
    return tower;
}
int main(){
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    int height[n], weight[n];
    cout << "Enter the heights of people: " << endl;
    for(int i = 0; i < n; ++i){
        cin >> height[i];
    }
    cout << "Enter the weights of people: " << endl;
    for(int i = 0; i < n; ++i){
        cin >> weight[i];
    }

    vector<pair<int, int>> tower = getMaxTower(height, weight, n);
    cout << "The maximum of height of tower is : " << tower.size() << endl;
    for(auto [u, v] : tower){
        cout << "(" << u << ", " << v << "), ";
    }
    cout << endl;
    return 0;
}
