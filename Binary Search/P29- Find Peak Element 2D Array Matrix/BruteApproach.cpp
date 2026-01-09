#include<bits/stdc++.h>
using namespace std;

pair<int,int> findPeakElement(vector<vector<int>> & mat, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j , m; j++){
            if((i == 0 || mat[i][j] >= mat[i-1][j]) &&
               (i == n-1 || mat[i][j] >= mat[i+1][j]) &&
               (j == 0 || mat[i][j] >= mat[i][j-1]) &&
                (j == m-1 || mat[i][j] >= mat[i][j+1])){
                return {i, j}; // Return the row and column indices of the peak element
            }

        }
    }
    return {-1, -1}; // Return {-1, -1} if no peak element is found
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
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
    if(peak.first != -1 && peak.second != -1){
        cout << "Peak element found at row: " << peak.first << ", column: " << peak.second << endl;
    }
    else{
        cout << "No peak element found in the matrix." << endl;
    }
}
