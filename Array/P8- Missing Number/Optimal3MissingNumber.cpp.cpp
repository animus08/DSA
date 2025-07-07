#include <bits/stdc++.h>
using namespace std;
vector<int> missingNumber(vector<int> &a, int n)
{
    int j = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != j)
        {
            return {j}; // If the current number is not equal to j, return j as the missing number
        }
        j++; // Increment j to check the next number
    }
    return {n}; // If all numbers are present, return n as the missing number
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) for the missing number, not counting the output array.
int main()
{
    vector<int> a{1, 3, 4, 5, 6, 7}; // Example array with a missing number
    int n = a.size() + 1;

    vector<int> result = missingNumber(a, n);
    cout << "Missing number in the array: " << result[0] << endl;
    return 0;
}
