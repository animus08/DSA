// Upper Bound- This code implements the upper bound function using binary search to find the first index
// where the target value is strictly less than the element at that index in the array.

#include <bits/stdc++.h>
using namespace std;

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

    int ans = upperBound(a, n, target);
    if (ans == n)
    {
        cout << "No element found greater than " << target << endl;
    }
    else
    {
        cout << "The upper bound of " << target << " is at index: " << ans << endl;
    }
}
