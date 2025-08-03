#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &a, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
            {
                prod = prod * a[k];
            }
            maxi = max(maxi, prod);
        }
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