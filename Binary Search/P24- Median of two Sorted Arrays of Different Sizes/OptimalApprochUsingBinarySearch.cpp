#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
    if (n1 > n2)
    {
        return findMedian(arr2, arr1, n2, n1); // Ensure arr1 is the smaller array
    }
    int low = 0, high = n1;
    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2; // Left half size

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
            // Found the correct partition
            if (n % 2 == 1)
                return (max(l1, l2));
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1; // Move towards left in arr1
        else low = mid1 + 1;
    }
    return 0;
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

    double median = findMedian(arr1, arr2, n1, n2);
    cout << "The median of the two sorted arrays is: " << fixed << setprecision(10) << median << endl;
}
