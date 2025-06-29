#include <bits/stdc++.h>
using namespace std;
void Zeros(vector<int> &arr, int n)
{

    vector<int> temp(n, 0); // Initialize a temporary array with zeros

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[j] = arr[i]; // Place non-zero elements in the temporary array
            j++;
        }
    }
// Fill the rest of the temporary array with zeros
    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";
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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array after moving zeros to the end: ";
    Zeros(arr, n);
}