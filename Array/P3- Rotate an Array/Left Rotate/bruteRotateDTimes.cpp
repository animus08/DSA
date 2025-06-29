#include <bits/stdc++.h>
using namespace std;
void leftRotate(vector<int> &arr, int n, int d)
{
    d = d % n;  // Handle cases where d >= n
    vector<int> temp(d);  // Temporary array to hold the first d elements
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];  // Store the first d elements in temp
    }
    for (int i = d; i < n ; i++)
    {
        arr[i - d] = arr[i];  // Shift the remaining elements to the left
    }
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];  // Place the stored elements at the end
    }
}
int main()
{
    int n;
    cin >> n;                               // Size of the array
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];                      // Input elements of the array
    }
    int d;
    cin >> d;                               // Number of times to rotate the array
    leftRotate(arr, n, d);                      // Call the rotate function
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";              // Output the rotated array
    }
    return 0;
}
