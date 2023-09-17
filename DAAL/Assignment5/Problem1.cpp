#include<iostream>
#include<vector>
using namespace std;
#define vii vector<vector<int>>
vii mult(vii m1, vii m2){
    int n = m1.size();
    vii ans(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return ans;
}
void print(vii &mat){
    for(auto row : mat){
        for(int elem : row){
            cout << elem << ' ';
        }
        cout << '\n';
    }
}
int main(){
    int n;
    cerr << "Enter the value of n : " << '\n';
    cin >> n;
    vector<vector<int>> m1(n, vector<int>(n));
    vector<vector<int>> m2(n, vector<int>(n));
    cerr << "Enter the first matrix : " << '\n';
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> m1[i][j];
        }
    }

    cerr << "Enter the second matrix : " << '\n';
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> m2[i][j];
        }
    }
    cerr << "---------------------------\n";
    vii ans = mult(m1, m2);
    print(m1);
    cout << "\nX\n\n";
    print(m2);
    cout << "\n=\n";
    print(ans);

    return 0;
}
