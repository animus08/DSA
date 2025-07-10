#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int> &a, int n, long long k)
{
    int right = 0, left = 0;
    long long sum = a[0];
    int maxlen = 0;
    while (right < n){
        while(left <= right && sum > k){
            sum  = sum - a[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if(right < n){
            sum = sum + a[right];
        }
    }
    if(maxlen == 0) {
        return {-1}; // If no subarray found, return -1
    }
    else {
        return {maxlen}; // Return the length of the longest subarray with sum k
    }
}



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

    long long k;
    cout << "Enter the sum k: ";
    cin >> k;

    vector<int> result = longestSubarray(arr, n, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result[0] << endl;
    return 0;
}
