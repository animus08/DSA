#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> a, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (a[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int lastOccurrence(vector<int> a, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (a[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

pair<int, int> firstAndLastOccurrence(vector<int> a, int n, int k)
{
    int first = firstOccurrence(a, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(a, n, k);
    return {first, last};
}

int countOccurrences(vector<int> &a, int n, int k)
{
    pair<int, int> ans = firstAndLastOccurrence(a, n, k);
    if (ans.first == -1)
        return 0;
    return (ans.second - ans.first + 1);
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

    int ans = countOccurrences(a, n, target);
    if (ans == 0)
    {
        cout << "Element " << target << " not found in the array." << endl;
    }
    else
    {
        cout << "Element " << target << " occurs " << ans << " times in the array." << endl;
    }
}
