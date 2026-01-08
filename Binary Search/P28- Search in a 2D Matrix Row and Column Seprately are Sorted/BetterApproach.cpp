#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &a, int n, int m, int target)
{
    int low = 0;
    int high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == target)
        {
            return true; // Return true if target is found
        }
        else if (a[mid] < target)
        {
            low = mid + 1; // Move to the right half
        }
        else
        {
            high = mid - 1; // Move to the left half
        }
    }
    return false; // Return false if target is not found
}

bool searchMatrix(vector<vector<int>> &mat, int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] <= target && mat[i][m - 1] >= target)
        {
            return binarySearch(mat[i], n, m, target);
        }
    }
    return false; // Return false if target is not found in the matrix
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

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    if (searchMatrix(mat, n, m, target) == true)
    {
        cout << "Element found in the matrix." << endl;
    }
    else
    {
        cout << "Element not found in the matrix." << endl;
    }
}




// If we want to return the row and col. no. of the target found then we have to write this code-

// #include <bits/stdc++.h>
// using namespace std;
// pair<int, int> binarySearch(vector<int> &a, int m, int target) {
//     int low = 0;
//     int high = m - 1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (a[mid] == target) {
//             return {0, mid}; // Return the column index if target is found
//         }
//         else if (a[mid] < target) {
//             low = mid + 1; // Move to the right half
//         }
//         else {
//             high = mid - 1; // Move to the left half
//         }
//     }
//     return {-1, -1}; // Return {-1, -1} if target is not found
// }

// pair<int, int> searchMatrix(vector<vector<int>> &mat, int n, int m, int target) {
//     for (int i = 0; i < n; i++) {
//         if (mat[i][0] <= target && mat[i][m - 1] >= target) {
//             pair<int, int> result = binarySearch(mat[i], m, target);
//             if (result.first != -1) {
//                 return {i, result.second}; // Return the row and column indices if target is found
//             }
//         }
//     }
//     return {-1, -1}; // Return {-1, -1} if target is not found in the matrix
// }

// int main() {
//     int n;
//     cout << "Enter the number of rows in the matrix: ";
//     cin >> n;

//     int m;
//     cout << "Enter the number of columns in the matrix: ";
//     cin >> m;

//     vector<vector<int>> mat(n, vector<int>(m));
//     cout << "Enter the elements of the matrix: " << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> mat[i][j];
//         }
//     }

//     cout << "Matrix entered:" << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }

//     int target;
//     cout << "Enter the target element to search: ";
//     cin >> target;

//     pair<int, int> result = searchMatrix(mat, n, m, target);
//     if (result.first != -1 && result.second != -1) {
//         cout << "Element found at row: " << result.first << ", column: " << result.second << endl;
//     }
//     else {
//         cout << "Element not found in the matrix." << endl;
//     }
//     return 0;
// }
