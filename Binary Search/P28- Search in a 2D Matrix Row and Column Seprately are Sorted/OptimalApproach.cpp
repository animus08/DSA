#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int n, int m, int target){
    int row = 0;
    int col = m-1; // Start from the top-right corner
    while(row < n && col >= 0){
        if(mat[row][col] == target){
            return true; // Return true if target is found
        }
        else if(mat[row][col] < target){
            row++; // Move down if the current element is less than target
        }
        else{
            col--; // Move left if the current element is greater than target
        }
    }
    return false; // Return false if target is not found
}

int main(){
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

// #include<bits/stdc++.h>
// using namespace std;
// pair<int, int> binarySearch(vector<vector<int>> &a, int n, int m, int target) {
//     int row = 0;
//     int col = m - 1;
//     while(row < n && col >= 0) {
//         if(a[row][col] == target) {
//             return {row, col}; // Return the row and column indices if target is found
//         }
//         else if(a[row][col] < target) {
//             row++; // Move down if the current element is less than target
//         }
//         else {
//             col--; // Move left if the current element is greater than target
//         }
//     }
//     return {-1, -1}; // Return {-1, -1} if target is not found
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

//     pair<int, int> result = binarySearch(mat, n, m, target);
//     if (result.first != -1 && result.second != -1) {
//         cout << "Element found at row: " << result.first << ", column: " << result.second << endl;
//     }
//     else {
//         cout << "Element not found in the matrix." << endl;
//     }
//     return 0;
// }
