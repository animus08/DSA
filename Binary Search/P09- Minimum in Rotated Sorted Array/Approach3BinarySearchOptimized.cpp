#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr, int n)
{
    int low = 0, high = n - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;  // If the array is not rotated, we can return the first element
        }
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
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

    int minimum = findMin(a, n);
    cout << "The minimum element in the rotated sorted array is: " << minimum << endl;
}
