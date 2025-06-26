#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix.empty() ? 0 : matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // 1. Traverse from left to right
        for (int i = left; i <= right; i++)
            result.push_back(matrix[top][i]);
        top++; // Move down to the next row

        // 2. Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        right--; // Move left to the previous column

        // 3. Traverse from right to left (only if top <= bottom)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--; // Move up to the previous row
        }

        // 4. Traverse from bottom to top (only if left <= right)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++; // Move right to the next column
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> spiral = spiralOrder(matrix);
    for (int val : spiral)
        cout << val << " ";

    return 0;
}
