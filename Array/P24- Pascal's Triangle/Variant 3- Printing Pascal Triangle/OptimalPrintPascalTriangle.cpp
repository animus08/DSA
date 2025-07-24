#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row)
{
    vector<int> ans;
    int res = 1;
    ans.push_back(1);

    for (int col = 1; col < row; col++)
    {
        res = res * (row - col);
        res = res / col;
        ans.push_back(res);
    }

    return ans;
}

vector<vector<int>> printPascalTriangle(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> tempRow = generateRow(row);
        ans.push_back(tempRow);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<vector<int>> result = printPascalTriangle(n);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = i + 1; j < result.size(); j++)
        {
            cout << " ";
        }
        for (int k = 0; k < result[i].size(); k++)
        {
            cout << result[i][k] << " ";
        }
        cout << endl;
    }
}