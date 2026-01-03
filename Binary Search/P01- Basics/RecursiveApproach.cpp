#include <bits/stdc++.h>
using namespace std;

int recursiveSearch(vector<int> arr, int low, int high, int target){
    if(low > high){
        return -1; // Element not found
    }
    int mid = low + (high - low) / 2; // To avoid overflow
    if(arr[mid] == target){
        return mid;
    }
    else if(target > arr[mid]){
        return recursiveSearch(arr, mid + 1, high, target);
    }
    else{
        return recursiveSearch(arr, low, mid - 1, target);
    }
}

int binarySearch(vector<int> &arr, int n, int target)
{
    return recursiveSearch(arr, 0, n - 1, target);
}

// Time Complexity: O(log base 2 n)
// Space Complexity: O(1)

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
}
