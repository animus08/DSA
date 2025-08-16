#include <bits/stdc++.h>
using namespace std;

vector <int> findPeakElement(vector<int> &arr, int n)
{
    vector<int> peaks;
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i] > arr[i - 1]) &&
            (i == n - 1 || arr[i] > arr[i + 1]))
        {
            peaks.push_back(arr[i]); // Found a peak element
        }
    }
    return peaks;
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

    vector<int> peakElements = findPeakElement(a, n);
    cout << "The peak elements in the array are: ";
    for (int peak : peakElements)
    {
        cout << peak << " ";
    }
}
