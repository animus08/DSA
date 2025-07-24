#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    int res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i+1);
    }
    return res;
}

int main()
{
    int row, col;
    cout << "Enter the row number: ";
    cin >> row;

    cout << "Enter the column number: ";
    cin >> col;

    int result = nCr(row - 1, col - 1);
    cout << "The value is: " << result << endl;
}