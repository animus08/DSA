#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n; // Initialize ans to n, which is out of bounds for valid indices

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= target)
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

int upperBound(vector<int> &a, int n, int target)
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

pair<int, int> firstAndLastOccurrence(vector<int> a, int n, int k)
{
    int first = lowerBound(a, n, k);
    if (first == n || a[first] != k)
        return {-1, -1};
    int last = upperBound(a, n, k);
    return {first, last-1};
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

    pair<int, int> ans = firstAndLastOccurrence(a, n, target);
    if (ans.first == -1)
    {
        cout << "Element not found in the array." << endl;
    }
    else
    {
        cout << "First occurrence of " << target << " is at index: " << ans.first << endl;
        cout << "Last occurrence of " << target << " is at index: " << ans.second << endl;
    }
}
