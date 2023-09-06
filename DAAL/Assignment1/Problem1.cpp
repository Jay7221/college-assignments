#include<iostream>
#include<vector>
using namespace std;
void merge(int a[], int b[], int n, int m){
    int ai = n - 1, bi = m - 1;
    for(int i = (n + m - 1); i >= 0; --i){
        if(ai < 0){
            a[i] = b[bi];
            --bi;
        }
        else if(bi < 0){
            a[i] = a[ai];
            --ai;
        }
        else{
            if(a[ai] >= b[bi]){
                a[i] = a[ai];
                --ai;
            }
            else{
                a[i] = b[bi];
                --bi;
            }
        }
    }
}
int main(){
    int n, m;
    cout << "Enter size of array A: ";
    cin >> n;
    cout << "Enter size of array B: ";
    cin >> m;
    int a[n + m], b[m];
    cout << "Enter elements of array A: ";
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << "Enter elements of array B: ";
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    cout << "Merging B to A ..." << endl;
    merge(a, b, n, m);
    cout << "The merged array A is : " << endl;
    for(int i = 0; i < n + m; ++i){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
