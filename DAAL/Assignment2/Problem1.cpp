#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check_repeat(vector<int> &v){
    sort(v.begin(), v.end());
    int n = v.size();
    for(int i = 1; i < n; ++i){
        if(v[i] == v[i - 1]){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cout << "Enter the size of array : " ;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    if(check_repeat(a)){
        cout << "Array contains repeated elements\n";
    }
    else{
        cout << "Array does not contain repeated elements\n";
    }
    return 0;
}
