#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZeros(vector<vector<int>> &matrix, int n, int m)
{
    // vector<int> rows(n, 0);  --> rows[..][0]
    // vector<int> cols(m, 0);  --> cols[0][..]
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if( j != 0){
                    matrix[0][j] = 0; // Mark the first row and first column
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(matrix[i][j] != 0){
                if (matrix[i][0] ==0 || matrix[0][j] == 0){
                    matrix[i][j] = 0; // Set the cell to zero if its row or column is marked
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0; // Set the first row to zero if needed
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0; // Set the first column to zero if needed
        }
    }

    return matrix;
}

int main()
{
    int n;
    cout << "Enter the no. of rows in a matrix: ";
    cin >> n;

    int m;
    cout << "Enter the no. of columns in a matrix: ";
    cin >> m; // Assuming a square matrix for simplicity

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements in a matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix before setting zeros is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = setMatrixZeros(matrix, n, m);
    cout << "The matrix after setting zeros is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}