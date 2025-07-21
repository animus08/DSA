#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int n){
    vector<vector<int>> result(n, vector<int>(n));

    int cnt = 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result[j][cnt] = matrix[i][j];      // We can also take n-i-1 instead of cnt
        }
        cnt--;
    }

    return result;
}

// Time Complexity: O(N^2) where N is the size of the matrix.
// Space Complexity: O(N^2) for the result matrix.

int main(){
    int n;
    cout << "Enter the no. of rows and columns in a matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements in a matrix: " << endl;
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix before rotation is: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = rotateMatrix(matrix, n);
    cout << "The matrix after rotation is: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}