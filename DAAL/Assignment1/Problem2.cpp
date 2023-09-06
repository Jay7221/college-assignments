#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortAnagrams(string arr[], int l, int r){
    if(l >= r){
        return;
    }
    int sz = r - l;
    vector<pair<string, string>> v(sz);
    for(int i = 0; i < sz; ++i){
        string s = arr[i + l];
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        v[i] = {sorted_s, s};
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < sz; ++i){
        arr[i + l] = v[i].second;
    }
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    string v[n];
    cout << "Enter the element of the array: ";
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    cout << "Sorting array so that anagrams are together ..." << endl;
    cout << "The elements of the sorted array are: " << endl;
    sortAnagrams(v, 0, n);
    for(int i = 0; i < n; ++i){
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
