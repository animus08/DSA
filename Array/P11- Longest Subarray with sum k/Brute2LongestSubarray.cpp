#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubaaray(vector<int> &a, int k, int n)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return {len};
}

// Time Complexity: O(N^3) where N is the size of the array.
// Space Complexity: O(1) as we are not using any extra space.

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

    int k;
    cout << "Enter the sum k: ";
    cin >> k;

    vector<int> result = longestSubaaray(arr, k, n);
    cout << "Length of the longest subarray with sum " << k << " is: " << result[0] << endl;
}