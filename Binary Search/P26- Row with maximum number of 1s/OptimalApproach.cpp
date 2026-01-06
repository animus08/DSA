#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n; // Initialize ans to n, which is out of bounds for valid indices

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &mat, int n, int m)
{
    int idx = -1; // Initialize index of row with maximum 1s
    int cnt_max = 0;

    for (int i = 0; i < n; i++){
        int cnt_ones = m - lowerBound(mat[i], m, 1);
        if (cnt_ones > cnt_max){
            cnt_max = cnt_ones; // Update maximum count of 1s
            idx = i; // Update index of row with maximum 1s
        }
    }
    return idx; // Return the index of the row with maximum 1s
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
