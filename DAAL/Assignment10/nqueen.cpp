#include<bits/stdc++.h>
using namespace std;
// board[i][j] = 1, there is a queen at square (i, j)
// otherwise the square (i, j) is empty

int n;
vector<vector<bool>> board;
bool canPlace(int row, int col){
    for(int i = row, j = col; (i >= 0) && (j >= 0); --i, --j){
        if(board[i][j]){
            return false;
        }
    }
    for(int i = row, j = col; (i >= 0) && (j < n); --i, ++j){
        if(board[i][j]){
            return false;
        }
    }
    for(int i = 0; i < row; ++i){
        if(board[i][col]){
            return false;
        }
    }
    return true;
}
bool place(int row){
    if(row == n){
        return true;
    }
    for(int col = 0; col < n; ++col){
        if(canPlace(row, col)){
            board[row][col] = true;
            if(place(row + 1)){
                return true;
            }
            board[row][col] = false;
        }
    }
    return false;
}
void fill(int n){
    board = vector<vector<bool>>(n, vector<bool>(n));
    place(0);
}
int main(){
    cerr << "Enter the length of side of the board: ";
    cin >> n;
    fill(n);
    for(int row = 0; row < n; ++row){
        for(int col = 0; col < n; ++col){
            if(board[row][col]){
                cout << 'Q';
            }
            else{
                cout << '.';
            }
        }
        cout << '\n';
    }
}
