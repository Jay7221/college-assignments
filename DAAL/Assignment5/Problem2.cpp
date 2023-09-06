#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}
// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix, int n = -1) {
    if(n == -1){
        n = matrix.size();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to multiply two matrices using Strassen's method
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrices are 1x1, just multiply them
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide each matrix into four submatrices
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));

    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));

    // Split matrices A and B into submatrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    if(half > 1){
        cout << "A11 : " << endl;
        printMatrix(A11);
        cout << "A12 : " << endl;
        printMatrix(A12);
        cout << "A21 : " << endl;
        printMatrix(A21);
        cout << "A22 : " << endl;
        printMatrix(A22);

        cout << "B11 : " << endl;
        printMatrix(B11);
        cout << "B12 : " << endl;
        printMatrix(B12);
        cout << "B21 : " << endl;
        printMatrix(B21);
        cout << "B22 : " << endl;
        printMatrix(B22);
    }

    // Compute intermediate matrices M1, M2, M3, M4, M5, M6, M7
    vector<vector<int>> M1 = strassenMultiply(A11, subtractMatrix(B12, B22));
    vector<vector<int>> M2 = strassenMultiply(addMatrix(A11, A12), B22);
    vector<vector<int>> M3 = strassenMultiply(addMatrix(A21, A22), B11);
    vector<vector<int>> M4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    vector<vector<int>> M5 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M6 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));
    vector<vector<int>> M7 = strassenMultiply(subtractMatrix(A11, A21), addMatrix(B11, B12));

    if(half > 1){
        cout << "M1 : " << endl;
        printMatrix(M1);
        cout << "M2 : " << endl;
        printMatrix(M2);
        cout << "M3 : " << endl;
        printMatrix(M3);
        cout << "M4 : " << endl;
        printMatrix(M4);
        cout << "M5 : " << endl;
        printMatrix(M5);
        cout << "M6 : " << endl;
        printMatrix(M6);
        cout << "M7 : " << endl;
        printMatrix(M7);
    }

    // Compute the four quadrants of the result matrix C
    vector<vector<int>> C11 = subtractMatrix(addMatrix(M5, M4), subtractMatrix(M2, M6));
    vector<vector<int>> C12 = addMatrix(M1, M2);
    vector<vector<int>> C21 = addMatrix(M3, M4);
    vector<vector<int>> C22 = subtractMatrix(addMatrix(M5, M1), addMatrix(M3, M7));

    // Combine the four quadrants to get the result matrix C
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    if(half > 1){
        cout << "C11 : " << endl;
        printMatrix(C11);
        cout << "C12 : " << endl;
        printMatrix(C12);
        cout << "C21 : " << endl;
        printMatrix(C21);
        cout << "C22 : " << endl;
        printMatrix(C22);
    }

    return C;
}


int main() {
    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;
    int N = 1;
    while(N < n){
        N <<= 1;
    }

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "Matrix B:" << endl;
    printMatrix(B);

    vector<vector<int>> result = strassenMultiply(A, B);

    cout << "Resultant Matrix C:" << endl;
    printMatrix(result, n);

    return 0;
}
