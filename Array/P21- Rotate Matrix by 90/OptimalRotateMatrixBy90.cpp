#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int n)
{
    // Transpose the matrix first
    // O(N/2 * N/2)
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row to get the 90-degree rotation
    // O(N*N/2)
    for(int i=0; i<n; i++){     // i- rows index
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}

// Time Complexity: O(N^2) where N is the size of the matrix.
// Space Complexity: O(1) since we are modifying the matrix in place.

int main()
{
    int n;
    cout << "Enter the no. of rows and columns in a matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements in a matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix before rotation is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = rotateMatrix(matrix, n);
    cout << "The matrix after rotation is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}