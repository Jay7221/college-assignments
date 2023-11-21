#include<bits/stdc++.h>
using namespace std;
double largest_profit(int n, int m, vector<int> w, vector<int> p){
    double ans = 0;
    vector<pair<double, double>> items(n);
    for(int i = 0; i < n; ++i){
        items[i] = {p[i], w[i]};
    }
    sort(items.rbegin(), items.rend());
    for(auto [p, w] : items){
        if(w <= m){
            m -= w;
            ans =+ p;
        }
    }
    return ans;
}
double smallest_weight(int n, int m, vector<int> w, vector<int> p){
    double ans = 0;
    vector<pair<double, double>> items(n);
    for(int i = 0; i < n; ++i){
        items[i] = {w[i], p[i]};
    }
    sort(items.begin(), items.end());
    for(auto [w, p] : items){
        if(w <= m){
            m -= w;
            ans += p;
        }
    }
    return ans;
}
double largest_profit_weight_ratio(int n, int m, vector<int> w, vector<int> p){
    double ans = 0;
    vector<tuple<double, double, double>> items(n);
    for(int i = 0; i < n; ++i){
        items[i] = {(double)p[i]/w[i], p[i], w[i]};
    }
    sort(items.rbegin(), items.rend());
    double capacity = m;
    for(auto [r, p, w] : items){
        cerr << r << ' ' << p << ' ' << w << '\n';
        double taken = min(w, capacity);
        double profit = p * min(w, capacity) / w;
        ans += profit;
        capacity -= min(w, capacity);
    }
    return ans;
}
int main(){
    int n, m;
    cerr << "Enter the number of items : " << endl;
    cin >> n;
    cerr << "Enter the capacity of kanpsack : " << endl;
    cin >> m;
    vector<int> w(n);
    cerr << "Enter the weights of items : " << endl;
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    vector<int> p(n);
    cerr << "Enter the profits of items : " << endl;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    cerr << "The maximum profit by largest profit strategy is : " << endl;
    cout << largest_profit(n, m, w, p) << endl;
    cerr << "The maximum profit by smallest weight strategy is : " << endl;
    cout << smallest_weight(n, m, w, p) << endl;
    cerr << "The maximum profit by largest profit/weight ratio strategy is : " << endl;
    cout << largest_profit_weight_ratio(n, m, w, p) << endl;
    return 0;
}
