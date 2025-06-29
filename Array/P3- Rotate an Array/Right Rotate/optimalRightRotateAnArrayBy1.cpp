#include <bits/stdc++.h>

using namespace std;
void solve(int arr[], int n)
{
    int temp = arr[n-1]; // storing the last element in a temporary variable
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1]; // shifting the elements to the right
    }
    arr[0] = temp; // assigning the last element to the first position
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// Time Complexity: O(n)
// Space Complexity: O(1)
int main()
{
    int n = 5;

    int arr[] = {1, 2, 3, 4, 5};
    solve(arr, n);
}
