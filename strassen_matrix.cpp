#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixAdd(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

vector<vector<int>> matrixSub(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide matrices into submatrices
    vector<vector<int>> A11(n/2, vector<int>(n/2)), A12(n/2, vector<int>(n/2)),
                        A21(n/2, vector<int>(n/2)), A22(n/2, vector<int>(n/2));
    vector<vector<int>> B11(n/2, vector<int>(n/2)), B12(n/2, vector<int>(n/2)),
                        B21(n/2, vector<int>(n/2)), B22(n/2, vector<int>(n/2));
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n/2];
            A21[i][j] = A[i + n/2][j];
            A22[i][j] = A[i + n/2][j + n/2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n/2];
            B21[i][j] = B[i + n/2][j];
            B22[i][j] = B[i + n/2][j + n/2];
        }
    }

    // Compute submatrices
    vector<vector<int>> P1 = strassenMultiply(matrixAdd(A11, A22), matrixAdd(B11, B22));
    vector<vector<int>> P2 = strassenMultiply(matrixAdd(A21, A22), B11);
    vector<vector<int>> P3 = strassenMultiply(A11, matrixSub(B12, B22));
    vector<vector<int>> P4 = strassenMultiply(A22, matrixSub(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(matrixAdd(A11, A12), B22);
    vector<vector<int>> P6 = strassenMultiply(matrixSub(A21, A11), matrixAdd(B11, B12));
    vector<vector<int>> P7 = strassenMultiply(matrixSub(A12, A22), matrixAdd(B21, B22));

    // Compute result submatrices
    vector<vector<int>> C11 = matrixAdd(matrixSub(matrixAdd(P1, P4), P5), P7);
    vector<vector<int>> C12 = matrixAdd(P3, P5);
    vector<vector<int>> C21 = matrixAdd(P2, P4);
    vector<vector<int>> C22 = matrixAdd(matrixSub(matrixAdd(P1, P3), P2), P6);

    // Combine result submatrices
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + n/2] = C12[i][j];
            C[i + n/2][j] = C21[i][j];
            C[i + n/2][j + n/2] = C22[i][j];
        }
    }

    return C;
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    vector<vector<int>> result = strassenMultiply(A, B);

    cout << "Resultant matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
