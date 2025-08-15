#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int> &arr, int n)
{
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high  = n-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid % 2 == 1 && arr[mid] == arr[mid-1]){
            low = mid + 1; // Move to the right half
        }
        else if(mid % 2 == 0 && arr[mid] == arr[mid+1]){
            low = mid + 1; // Move to the right half
        }
        else{
            high = mid - 1; // Move to the left half
        }
    }
    return -1;
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

    int singleElement = searchElement(a, n);
    cout << "The single element in the sorted array is: " << singleElement << endl;
}
