#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

struct Building {
    int left, ht, right;
    Building(int l, int h, int r) : left(l), ht(h), right(r) {}
};
ostream& operator<<(ostream& out, const Building &b){
    out << "(" << b.left << ' ' << b.ht << ' ' << b.right << ")";
    return out;
}

vector<pair<int, int>> mergeSkyline(vector<Building>& buildings, int left, int right) {
    if (left == right) {
        vector<pair<int, int>> result;
        result.push_back({buildings[left].left, buildings[left].ht});
        result.push_back({buildings[left].right, 0});
        return result;
    }

    int mid = (left + right) / 2;
    vector<pair<int, int>> leftSkyline = mergeSkyline(buildings, left, mid);
    vector<pair<int, int>> rightSkyline = mergeSkyline(buildings, mid + 1, right);
    
    int i = 0, j = 0, h1 = 0, h2 = 0;
    vector<pair<int, int>> mergedSkyline;
    vector<Building> cur;
    for(int i = left; i <= right; ++i){
        cur.push_back(buildings[i]);
    }
    cerr << "Buildings : " << cur << '\n';
    cerr << "Left Skyline : " << leftSkyline << '\n';
    cerr << "Right Skyline : " << rightSkyline << '\n';
    cerr << "\n-----------------------\n\n";
    
    while (i < leftSkyline.size() && j < rightSkyline.size()) {
        int x;
        int h;
        if (leftSkyline[i].first < rightSkyline[j].first) {
            x = leftSkyline[i].first;
            h = leftSkyline[i].second;
            i++;
        } else if (leftSkyline[i].first > rightSkyline[j].first) {
            x = rightSkyline[j].first;
            h = rightSkyline[j].second;
            j++;
        } else {
            x = leftSkyline[i].first;
            h = max(leftSkyline[i].second, rightSkyline[j].second);
            i++;
            j++;
        }
        
        if (mergedSkyline.empty() || h != mergedSkyline.back().second) {
            mergedSkyline.push_back({x, h});
        }
    }
    
    while (i < leftSkyline.size()) {
        mergedSkyline.push_back(leftSkyline[i]);
        i++;
    }
    
    while (j < rightSkyline.size()) {
        mergedSkyline.push_back(rightSkyline[j]);
        j++;
    }
    
    return mergedSkyline;
}

vector<pair<int, int>> getSkyline(vector<Building>& buildings) {
    if (buildings.empty()) {
        return vector<pair<int, int>>();
    }
    
    return mergeSkyline(buildings, 0, buildings.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<Building> buildings;
    for(int i = 0; i < n; ++i){
        int x, h, y;
        cin >> x >> h >> y;
        buildings.push_back(Building(x, h, y));
    }

    vector<pair<int, int>> skyline = getSkyline(buildings);

    cout << skyline << '\n';

    return 0;
}
