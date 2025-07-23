#include <bits/stdc++.h>
using namespace std;

int countSubarraySum(vector<int> &a, int n, int target)
{
    map<int, int> mpp;
    mpp[0] = 1;
    int cnt = 0, preSum = 0;
    for(int i = 0; i<n; i++){
        preSum += a[i];
        int remove = preSum - target;
        cnt += mpp[remove];
        mpp[preSum]++;
    }
    return cnt;
}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, 
//                  where N = size of the array.
// Space Complexity: O(N) as we are using a map data structure.

int main()
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int result = countSubarraySum(a, n, target);
    cout << "Number of subarrays with sum equal to " << target << ": " << result << endl;
}