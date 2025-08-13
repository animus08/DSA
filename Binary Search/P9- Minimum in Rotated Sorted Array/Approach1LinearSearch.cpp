#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr, int n){
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    return mini;
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
