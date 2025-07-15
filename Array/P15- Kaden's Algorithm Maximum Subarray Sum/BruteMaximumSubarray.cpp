#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int> &a, int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += a[k];
                maxSum = max(maxSum, sum);
            }
        }
    }
    return maxSum;
}

// Time Complexity: O(n^3)
// Space Complexity: O(1) (not counting the input array)

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

    cout << "Maximum Subarray Sum: " << maximumSubarraySum(a, n) << endl;
    return 0;
}