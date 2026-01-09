#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col){
    int maxValue = -1;
    int index = -1;
    for(int i = 0; i < n; i++){
        if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index; // Return the row index of the maximum element in the specified column
}

pair<int, int> findPeakElement(vector<vector<int>> &mat, int n, int m)
{
    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = (low + high) / 2;
        int maxRow = findMaxIndex(mat, n, m, mid);

        int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1; // Check left neighbor
        int right = mid + 1 < m ? mat[maxRow][mid + 1] : -1; // Check right neighbor

        if(mat[maxRow][mid] > left && mat[maxRow][mid] > right){
            return {maxRow, mid}; // Return the row and column indices of the peak element
        }
        else if(left > mat[maxRow][mid]){
            high = mid - 1; // Move to the left half
        }
        else{
            low = mid + 1; // Move to the right half
        }
    }
    return {-1, -1}; // Return {-1, -1} if no peak element is found
}

int main()
{
    int n;
    cout << "Enter the number of rows in the matrix: ";
    cin >> n;

    int m;
    cout << "Enter the number of columns in the matrix: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Matrix entered:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    pair<int, int> peak = findPeakElement(mat, n, m);
    if (peak.first != -1 && peak.second != -1)
    {
        cout << "Peak element found at row: " << peak.first << ", column: " << peak.second << endl;
    }
    else
    {
        cout << "No peak element found in the matrix." << endl;
    }
}
