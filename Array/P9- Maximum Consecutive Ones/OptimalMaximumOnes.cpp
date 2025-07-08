#include <bits/stdc++.h>
using namespace std;
vector<int> maxConsecutiveOnes(vector<int> &a, int n)
{
    int maxi = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt); // Update maximum count of consecutive 1s
        }
        else
        {
            cnt = 0;
        }
    }

    return {maxi};
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) for the maximum count, not counting the output array.
int main()
{
    vector<int> a{1, 1, 0, 1, 1, 1, 1, 0, 1, 1}; // Example array with a missing number
    int n = a.size();

    vector<int> result = maxConsecutiveOnes(a, n);
    cout << "Maximum consecutive ones in an array: " << result[0] << endl;
    return 0;
}