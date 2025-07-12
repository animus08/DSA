#include <bits/stdc++.h>
using namespace std;

vector<int> sort012(vector<int> a, int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            cnt0++;
        else if (a[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++)
        a[i] = 0;

    for (int i = cnt0; i < cnt0 + cnt1; i++)
        a[i] = 1;

    for (int i = cnt0 + cnt1; i < n; i++)
        a[i] = 2;

    return a;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (not counting the input array)

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array (0s, 1s, and 2s): ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> sortedArray = sort012(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << sortedArray[i] << " ";
    }
}