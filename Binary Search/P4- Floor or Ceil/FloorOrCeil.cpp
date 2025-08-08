#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // look on the right
        }
    }
    return ans;
}

int findCeil(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

vector <int> getFloorAndCeil(vector<int> arr, int n, int x)
{
    vector<int> result(2);
    int floorValue = findFloor(arr, n, x);
    int ceilValue = findCeil(arr, n, x);

    result[0] = floorValue; // Floor value
    result[1] = ceilValue;  // Ceil value
    return result;
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

    vector <int> ans = getFloorAndCeil(a, n, target);
    cout << "Floor: " << ans[0] << ", Ceil: " << ans[1] << endl;
}
