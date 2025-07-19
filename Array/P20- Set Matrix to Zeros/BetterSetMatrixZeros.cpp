#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZeros(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> rows(n,0);
    vector<int> cols(m,0);

    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m ; j++){
            if(rows[i] == 1 || cols[j] == 1){
                matrix[i][j] = 0;
            }
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