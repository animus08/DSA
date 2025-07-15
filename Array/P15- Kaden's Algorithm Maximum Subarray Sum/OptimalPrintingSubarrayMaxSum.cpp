#include <bits/stdc++.h>
using namespace std;

vector<int> maximumSubarraySum(vector<int> &a, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int start = -1, end = -1;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0) // Reset start index when sum is reset
        {
            start = i;
        }
        sum += a[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            end = i; // Update end index when maxSum is updated
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if(maxSum < 0)
    {
        result.push_back(0); // If all elements are negative, return 0
    }
    else
    {
        cout << "Maximum Subarray sum is: " << maxSum << endl;
        for(int i = start; i<= end; i++)
        {
            result.push_back(a[i]); // Store the subarray with maximum sum
        }
    }
    return result; // Return the subarray with maximum sum
}

// Time Complexity: O(n)
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

    vector<int> result = maximumSubarraySum(a, n);
    cout << "Subarray with maximum sum is: ";
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}