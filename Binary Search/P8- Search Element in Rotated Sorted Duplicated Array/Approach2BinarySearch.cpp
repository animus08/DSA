#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<int> &arr, int n, int k)
{
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            return true;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue; // Skip duplicates
        }
        if (arr[low] <= arr[mid]){
            if (arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{

                low = mid + 1;
            }
        }
        else{
            if (arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
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
    cout << "Enter the target element: ";
    cin >> target;

    bool found = searchElement(a, n, target);
    if (found)
    {
        cout << "Element found in the array." << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
}
