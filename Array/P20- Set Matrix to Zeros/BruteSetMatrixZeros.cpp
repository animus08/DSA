#include<bits/stdc++.h>
using namespace std;

void markRows(vector<vector<int>> &matrix, int n, int m, int i)
{
    for(int j=0; j<m; j++){
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCols(vector<vector<int>> &matrix, int n, int m, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> setMatrixZeros(vector<vector<int>> &matrix, int n, int m){

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if (matrix[i][j] == 0)
            {
                markRows(matrix, n, m, i);
                markCols(matrix, n, m, j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// Time Complexity: O(n*m) * O(n + m) + O(n*m)
// Space Complexity: O(N^3) for the matrix

int main(){
    int n;
    cout << "Enter the no. of rows in a matrix: ";
    cin >> n;

    int m;
    cout << "Enter the no. of columns in a matrix: ";
    cin >> m; // Assuming a square matrix for simplicity

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements in a matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix before setting zeros is: " << endl;
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = setMatrixZeros(matrix, n, m);
    cout << "The matrix after setting zeros is: " << endl;
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}