#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int nCr(int n, int r){
    int ans;
    ans = factorial(n) / (factorial(r) * factorial(n-r));
    return ans;
}

int main(){
    int row, col;
    cout << "Enter the row number: ";
    cin >> row;

    cout << "Enter the column number: ";
    cin >> col;

    int result = nCr(row - 1, col - 1);
    cout << "The value is: " << result << endl;
}