#include <bits/stdc++.h>
using namespace std;

vector<int> printRow(int row)
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

int main()
{
    int row;
    cout << "Enter the row number: ";
    cin >> row;

    vector<int> result = printRow(row);
    for (int i = 0; i < row; i++)
    {
        cout << result[i] << " ";
    }
}