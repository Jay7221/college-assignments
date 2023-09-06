#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int* p = a;
    for(int i = 0; i < n; ++i, p){
        cin >> *p;
        ++p;
    }
    p = a;
    while(n--){
        cout << *p << ' ';
        ++p;
    }
    cout << endl;
}