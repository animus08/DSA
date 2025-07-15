#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int> &a, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum>maxSum){
            maxSum  = max(maxSum, sum);
        }
        if(sum<0){
            sum = 0;
        }
    }
    if(maxSum < 0){
        return 0; // If all elements are negative, return 0
    }
    else{
        return maxSum; // Return the maximum subarray sum
    }
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

    cout << "Maximum Subarray Sum: " << maximumSubarraySum(a, n) << endl;
    return 0;
}