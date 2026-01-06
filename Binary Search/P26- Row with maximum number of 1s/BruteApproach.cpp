#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &mat, int n, int m)
{
    int idx = -1;      // Initialize index of row with maximum 1s
    int maxCount = -1; // Initialize maximum count of 1s
    for (int i = 0; i < n; i++)
    {
        int cnt_row = 0; // Count of 1s in the current row
        for (int j = 0; j < m; j++)
        {
            cnt_row += mat[i][j]; 
        }
        if (cnt_row > maxCount)
        {
            maxCount = cnt_row; // Update maximum count of 1s
            idx = i;             // Update index of row with maximum 1s
        }
    }
    return idx; // Return the index of the row with maximum 1s
}

int main(){
    int n;
    cout << "Enter the number of rows in the matrix: ";
    cin >> n;

    int m;
    cout << "Enter the number of columns in the matrix: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix (0s and 1s only):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int result = rowWithMax1s(mat, n, m);
    if (result == -1)
    {
        cout << "No row with 1s found." << endl;
    }
    else
    {
        cout << "Row with maximum number of 1s is at index: " << result << endl;
    }
}
