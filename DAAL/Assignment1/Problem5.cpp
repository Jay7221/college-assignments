#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
pair<int, int> search(int mat[], int n, int m, int target){
    int rl = 0, rr = n - 1;
    while(rl < rr){
        int mid = (rl + rr) / 2;
        if(mat[mid * m + m - 1] < target){
            rl = mid + 1;
        }
        else{
            rr = mid;
        }
    }
    int row = rl;
    int cl = 0, cr = m - 1;
    while(cl < cr){
        int mid = (cl + cr) / 2;
        if(mat[mid * m + mid] < target){
            cl = mid + 1;
        }
        else{
            cr = mid;
        }
    }
    int col = cl;
    return {row, col};
}
int main(){
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "Enter the matrix : " << endl;
    int mat[n * m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i * m + j];
        }
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    cout << "Computing the index of target value..." << endl;
    int row, col;
    tie(row, col) = search(mat, n, m, target);
    cout << "The coordinates of target are: " << row << ' ' << col << endl;
    return 0;
}
