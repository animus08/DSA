#include<bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> result;
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;

    while(top <= bottom && left <= right){
        for(int i = left; i<= right; i++){
        result.push_back(matrix[top][i]);
        }
        top++;

        for(int i = top; i<=bottom; i++){
            result.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i=right; i>=left; i--){
            result.push_back(matrix[bottom][i]);
            }
        }
        bottom--;

        if(left <= right){
            for(int i=bottom; i>=top; i--){
                result.push_back(matrix[i][left]);
            }
        }
        left++;
    }

    return result;
}
int main(){
    int n;
    cout << "Enter the no. of rows in a matrix: ";
    cin >> n;

    int m;
    cout << "Enter the no. of columns in a matrix: ";
    cin >> m; 

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements in a matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix before rotation is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> result = spiralTraversal(matrix, n, m);
    cout << "The matrix after spiral traversal is: " << endl;
    for(int  i = 0; i<n*m ; i++){
        cout << result[i] << " ";
    }
}