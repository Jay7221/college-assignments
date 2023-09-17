#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl; // Add a blank line for separation
}

void fillBoard(vector<vector<int>>& board, int tr, int tc, int dr, int dc, int size, int missingRow, int missingCol) {
    if (size == 2) {
        int tile = 1;
        for (int i = tr; i < tr + 2; i++) {
            for (int j = tc; j < tc + 2; j++) {
                if (i != missingRow || j != missingCol) {
                    board[i][j] = tile;
                }
                tile++;
            }
        }
        printBoard(board); // Print the board at this stage
    } else {
        int newSize = size / 2;
        int tile = size * size / 4;
        int originalTr = tr;
        int originalTc = tc;
        
        if (dr < tr + newSize && dc < tc + newSize) {
            // Missing cell is in the top-left quadrant
            missingRow = tr + newSize - 1;
            missingCol = tc + newSize - 1;
        } else if (dr < tr + newSize) {
            // Missing cell is in the top-right quadrant
            tc += newSize;
            missingRow = tr + newSize - 1;
        } else if (dc < tc + newSize) {
            // Missing cell is in the bottom-left quadrant
            tr += newSize;
            missingCol = tc + newSize - 1;
        } else {
            // Missing cell is in the bottom-right quadrant
            tr += newSize;
            tc += newSize;
        }
        
        // Recursively fill the four quadrants
        fillBoard(board, originalTr, originalTc, tr, tc, newSize, missingRow, missingCol);
        fillBoard(board, originalTr, originalTc + newSize, tr, tc + newSize, newSize, missingRow, missingCol);
        fillBoard(board, originalTr + newSize, originalTc, tr + newSize, tc, newSize, missingRow, missingCol);
        fillBoard(board, originalTr + newSize, originalTc + newSize, tr + newSize, tc + newSize, newSize, missingRow, missingCol);
    }
}

int main() {
    int n;
    cout << "Enter the value of n (power of 2): ";
    cin >> n;

    if (n < 2 || (n & (n - 1)) != 0) {
        cout << "Invalid input. n should be a power of 2 with a minimum value of 2." << endl;
        return 1;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    int missingRow, missingCol;
    cout << "Enter the row and column of the missing cell (0-based index): ";
    cin >> missingRow >> missingCol;

    if (missingRow < 0 || missingRow >= n || missingCol < 0 || missingCol >= n) {
        cout << "Invalid missing cell position." << endl;
        return 1;
    }

    fillBoard(board, 0, 0, 0, 0, n, missingRow, missingCol);

    cout << "Filled board:" << endl;
    printBoard(board);

    return 0;
}
