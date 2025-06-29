#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rightRotate(vector<int> &arr, int n, int d)
{
    reverse (arr, 0, n - d - 1);
    reverse (arr, n - d, n - 1);
    reverse (arr, 0, n - 1);
}
// Time Complexity: O(n)
// Space Complexity: O(1)
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n; 
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int d;
    cout << "Enter the number of times to rotate the array: ";
    cin >> d;
    d = d % n;
    rightRotate(arr, n, d);

    cout<< "Rotated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}