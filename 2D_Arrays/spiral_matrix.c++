#include<iostream>
using namespace std;

void spiralMatrix(int mat[4][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    while (srow <= erow && scol <= ecol) {
        // top
        for (int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }
        // right
        for (int i = srow + 1; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }
        // bottom
        if (srow != erow) {
            for (int j = ecol - 1; j >= scol; j--) {
                cout << mat[erow][j] << " ";
            }
        }
        // left
        if (scol != ecol) {
            for (int i = erow - 1; i > srow; i--) {
                cout << mat[i][scol] << " ";
            }
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    cout << endl;
}

int main() {
    int matrix[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int n = 4;
    int m = 4;
    spiralMatrix(matrix, n, m);
}