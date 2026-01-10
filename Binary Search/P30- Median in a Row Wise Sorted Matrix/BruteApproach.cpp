#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &mat, int r, int c){
    vector<int> ans;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ans.push_back(mat[i][j]);
        }
    }

    sort(ans.begin(), ans.end());

    return ans[(r * c) / 2]; // Return the median element
}

int main(){
    int r;
    cout << "Enter the number of rows in the matrix: ";
    cin >> r;

    int c;
    cout << "Enter the number of columns in the matrix: ";
    cin >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    cout << "Enter the elements of the matrix (row-wise):" << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    int result = median(mat, r, c);
    cout << "The median of the matrix is: " << result << endl;
    
}
