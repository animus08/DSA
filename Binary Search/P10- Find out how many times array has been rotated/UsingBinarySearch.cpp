#include <bits/stdc++.h>
using namespace std;

int countRotations(vector<int> &arr, int n){
    int low = 0, high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else{
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
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

    int rotations = countRotations(a, n);
    cout << "The array has been rotated " << rotations << " times." << endl;
}
