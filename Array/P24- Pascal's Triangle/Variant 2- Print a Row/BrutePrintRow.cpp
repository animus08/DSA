#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

vector<int> printRow(int row){
    vector<int> ans;
    for(int col = 1; col <= row; col++){
        ans.push_back(nCr(row-1, col-1));
    }
    return ans;
}

int main()
{
    int row;
    cout << "Enter the row number: ";
    cin >> row;


    vector<int> result = printRow(row);
    for(int i=0; i<row; i++){
        cout<< result[i] << " ";
    }
}