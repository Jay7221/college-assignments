#include <iostream>
#include <vector>
#include<map>

using namespace std;

map<int, int> num_op;

vector<vector<int>> operator+ (vector<vector<int>> a, vector<vector<int>> b){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> c(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
vector<vector<int>> operator- (vector<vector<int>> a, vector<vector<int>> b){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> c(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}

ostream& operator<< (ostream& out, vector<vector<int>> &mat){
    for(auto row : mat){
        for(int elem : row){
            out << elem << ' ';
        }
        out << '\n';
    }
    return out;
}

// Function to multiply two matrices using Strassen's method
vector<vector<int>> operator*(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Increment the number of multiplcations of two n X n matrices
    ++num_op[n];

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
        cerr << "A11 : " << '\n' << A11 << '\n';
        cerr << "A12 : " << '\n' << A12 << '\n';
        cerr << "A21 : " << '\n' << A21 << '\n';
        cerr << "A22 : " << '\n' << A22 << '\n';

        cerr << "B11 : " << '\n' << B11 << '\n';
        cerr << "B12 : " << '\n' << B12 << '\n';
        cerr << "B21 : " << '\n' << B21 << '\n';
        cerr << "B22 : " << '\n' << B22 << '\n';
    }

    // Compute intermediate matrices M1, M2, M3, M4, M5, M6, M7
    vector<vector<int>> M1 = (A11 + A22) * (B11 + B22);
    vector<vector<int>> M2 = (A21 + A22) * B11;
    vector<vector<int>> M3 = A11 * (B12 - B22);
    vector<vector<int>> M4 = A22 * (B21 - B11);
    vector<vector<int>> M5 = (A11 + A12) * B22;
    vector<vector<int>> M6 = (A21 - A11) * (B11 + B12);
    vector<vector<int>> M7 = (A12 - A22) * (B21 + B22);

    if(half > 1){
        cerr << "M1 : " << '\n' << M1 << '\n';
        cerr << "M2 : " << '\n' << M2 << '\n';
        cerr << "M3 : " << '\n' << M3 << '\n';
        cerr << "M4 : " << '\n' << M4 << '\n';
        cerr << "M5 : " << '\n' << M5 << '\n';
        cerr << "M6 : " << '\n' << M6 << '\n';
        cerr << "M7 : " << '\n' << M7 << '\n';
    }

    // Compute the four quadrants of the result matrix C
    vector<vector<int>> C11 = M1 + M4 - M5 + M7;
    vector<vector<int>> C12 = M3 + M5;
    vector<vector<int>> C21 = M2 + M4;
    vector<vector<int>> C22 = M1 - M2 + M3 + M6;

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
        cerr << "C11 : " << '\n' << C11 << '\n';
        cerr << "C12 : " << '\n' << C12 << '\n';
        cerr << "C21 : " << '\n' << C21 << '\n';
        cerr << "C22 : " << '\n' << C22 << '\n';
    }

    return C;
}


int main() {
    int n;
    cerr << "Enter the size of the matrices: ";
    cin >> n;
    int N = 1;
    while(N < n){
        N <<= 1;
    }

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    cerr << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cerr << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    cerr << "Matrix A:" << '\n' << A;

    cerr << "Matrix B:" << '\n' << B;

    vector<vector<int>> C = A * B;
    C.resize(n);
    for(auto &v : C){
        v.resize(n);
    }

    cerr << "Resultant Matrix C:" << '\n';
    cout << C;

    for(auto [n, f] : num_op){
        if(f > 0){
            cerr << "Number of operations of " << n << " X " << n << " matrices is " << " : " << f << '\n';
        }
    }

    return 0;
}
