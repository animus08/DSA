#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int> &a, int n, long long k)
{
    map <long long, int> preSumMap; // Map to store prefix sums and their indices
    long long sum = 0;
    int maxlen = 0; // Variable to store the length of the longest subarray
    for(int i = 0; i < n; i++){
        sum += a[i]; // Calculate the prefix sum
        if(sum == k) {
            maxlen = i + 1; // If the prefix sum equals k, update maxlen
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem]; // Calculate the length of the subarray
            maxlen = max(maxlen, len); // Update maxlen if the current length is greater
        }
        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i; // Store the index of the prefix sum if it is not already present
        }
    }
    if(maxlen == 0) {
        return {-1}; // If no subarray found, return -1
    }
    else {
        return {maxlen}; // Return the length of the longest subarray with sum k
    }
}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Space Complexity: O(N) as we are using a map data structure.

int main() {
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
}

// This code works well in the array with negative numbers and positive numbers.