#include <bits/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int> &a, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n; // Initialize ans to n, which is out of bounds for valid indices

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

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

    int target;
    cout << "Enter the target elements: ";
    cin >> target;

    int ans = searchInsertPosition(a, n, target);

    if (ans == n)
    {
        cout << "Target is greater than all elements. Insert at the end.\n";
    }
    else if (ans == 0)
    {
        cout << "Insert at the beginning.\n";
    }
    else
    {
        cout << "Insert between index " << ans - 1 << " and " << ans << ".\n";
    }

    cout << "Array after insertion: ";
    for (int i = 0; i <= n; i++)
    {
        if (i == ans)
        {
            cout << target << " ";
        }
        if (i < n)
        {
            cout << a[i] << " ";
        }
    }
}
