#include <bits/stdc++.h>
using namespace std;

int findKthElement(vector<int> &arr1, vector<int> &arr2, int n1, int n2, int k)
{
    if (n1 > n2)
    {
        return findKthElement(arr2, arr1, n2, n1, k);
    }
    int low = max(0, k-n2), high = min(k, n1);
    int n = n1 + n2;
    int left = k;

    while (low <= high)
    {
        int mid1 = (low + high) / 2; // Midpoint in arr1
        int mid2 = left - mid1;      // Corresponding midpoint in arr2
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = arr1[mid1]; // Right element in arr1
        if (mid2 < n2)
            r2 = arr2[mid2]; // Right element in arr2
        if (mid1 > 0)
            l1 = arr1[mid1 - 1];
        if (mid2 > 0)
            l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2); // Found the k-th element
        }
        else if (l1 > r2)
            high = mid1 - 1; // Move towards left in arr1
        else
            low = mid1 + 1;
    }
    return -1; // If k is out of bounds
}
int main()
{
    int n1;
    cout << "Enter the size of first sorted array: ";
    cin >> n1;

    vector<int> arr1(n1);
    cout << "Enter the elements of first sorted array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cout << "Enter the size of second sorted array: ";
    cin >> n2;

    vector<int> arr2(n2);
    cout << "Enter the elements of second sorted array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int k;
    cout << "Enter the value of k to find the k-th element: ";
    cin >> k;

    int kthElement = findKthElement(arr1, arr2, n1, n2, k);
    if (kthElement != -1)
        cout << "The " << k << "-th element of the two sorted arrays is: " << kthElement << endl;
    else
        cout << "Invalid k value!" << endl;
}
