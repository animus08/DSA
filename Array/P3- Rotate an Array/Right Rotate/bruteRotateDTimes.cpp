#include<bits/stdc++.h>
using namespace std;
void rightRotate(vector<int> &arr, int n, int d)
{
    vector<int> temp(n);
    // Copy last d elements to temp
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[n - d + i];
    }
    // Shift the rest to the right
    for (int i = n - 1; i >= d; i--)
    {
        arr[i] = arr[i - d];
    }
    // Copy temp to the front
    for (int i = 0; i < d; i++)
    {
        arr[i] = temp[i];
    }
}
// Time Complexity: O(n)
// Space Complexity: O(n)
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cout << "Enter the number of times to rotate the array: ";
    cin >> d;

    d = d % n; // To handle cases where d >= n
    rightRotate(arr, n, d);

    cout << "Array after right rotation: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}