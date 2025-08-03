#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &a, int n)
{
    int maxi = INT_MIN;
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * a[i];
        suffix = suffix * a[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxProduct = maximumProduct(a, n);
    cout << "Maximum product subarray is: " << maxProduct << endl;
}