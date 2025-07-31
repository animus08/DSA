#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeating(vector<int> &a)
{
    long long n = a.size();
    long long SN = (n * (n + 1)) / 2;       // X^2
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;        // Y^2

    long long S = 0, S2 = 0;

    for(int i = 0; i < n; i++){
        S += a[i];          // X
        S2 += (long long)a[i]*a[i];         // Y
    }

    long long val1 = S - SN;            // X - Y
    long long val2 = S2 - S2N;          // X^2 - Y^2
    val2 = val2 / val1;         // (X^2 - Y^2) / (X - Y) = X + Y    

    int x = (val1 + val2) / 2;          
    int y = x - val1;

    return {y, x};
}

// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = findMissingAndRepeating(arr);
    cout << "Missing Number: " << result[0] << endl;
    cout << "Repeating Number: " << result[1] << endl;
}