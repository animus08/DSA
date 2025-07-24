#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> printPascalTriangle(int n)
{
    vector<vector<int>> ans;
    
    for(int row = 1; row<=n; row++){
        vector<int> tempLst;
        for(int col = 1; col<=row; col++){
            tempLst.push_back(nCr(row-1, col-1));
        }
        ans.push_back(tempLst);
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
        for(int j = i + 1; j< result.size(); j++){
            cout << " ";
        }
        for(int k = 0; k<result[i].size(); k++)
        {
            cout << result[i][k] << " ";
        }
        cout << endl;
    }
}