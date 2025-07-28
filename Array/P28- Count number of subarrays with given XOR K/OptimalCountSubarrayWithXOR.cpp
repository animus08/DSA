#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXOR(vector<int> &a, int n, int K)
{
    int cnt = 0;
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++;

    for(int i = 0; i<n; i++){
        xr = xr ^ a[i];
        int x = xr ^ K;
        cnt  = cnt + mpp[x];
        mpp[xr]++;
    }

    return cnt;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cout << "Enter the target XOR: ";
    cin >> k;

    int result = countSubarraysWithXOR(a, n, k);
    cout << "The no. of subarrays with XOR is: " << result << endl;
}