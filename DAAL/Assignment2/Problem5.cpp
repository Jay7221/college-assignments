#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool find(vector<int> &a, vector<int> &b, int target){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size(), m = b.size();
    int l = 0, r = m - 1;
    while((l < n) && (r >= 0)){
        if(a[l] + b[r] == target){
            return true;
        }
        if(a[l] + b[r] < target){
            ++l;
        }
        else{
            --r;
        }
    }
    l = 0, r = n - 1;
    while((l < m) && (r >= 0)){
        if(b[l] + a[r] == target){
            return true;
        }
        if(b[l] + a[r] < target){
            ++l;
        }
        else{
            --r;
        }
    }
    return false;
}
int main(){
    int n, m;

    cout << "Enter the size of array A : " ;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << "Enter the size of array B : " ;
    cin >> m;
    vector<int> b(m);
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }

    int k;
    cout << "Enter the target k : ";
    cin >> k;
    if(find(a, b, k)){
        cout << "There exists a and b in A such that a + b = k" << endl;
    }
    else{
        cout << "There exists no a and b in A such that a + b = k" << endl;
    }
    return 0;
}
