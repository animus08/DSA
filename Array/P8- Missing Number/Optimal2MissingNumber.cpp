#include <bits/stdc++.h>
using namespace std;
vector<int> missingNumber(vector<int> &a, int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n -1; i++){
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n; // Include the last number n in the XOR calculation
    return {xor1 ^ xor2}; // The missing number is the XOR of the two results
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) for the missing number, not counting the output array.
int main()
{
    vector<int> a{1, 2, 3, 4, 6}; // Example array with a missing number
    int n = a.size() + 1;

    vector<int> result = missingNumber(a, n);
    cout << "Missing number in the array: " << result[0] << endl;
    return 0;
}
// This is used so that we can store a large number of elements in the array.
// 1^1=0, 1^0=1, 0^0=0, 0^1=1