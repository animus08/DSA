#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithXOR(vector<int> &a, int n, int K)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xorSum = 0;
        for (int j = i; j < n; j++)
        {
            xorSum = xorSum ^ a[j];
            if (xorSum == K)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

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