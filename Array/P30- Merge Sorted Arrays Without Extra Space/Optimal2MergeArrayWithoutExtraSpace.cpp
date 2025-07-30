#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int> &a1, vector<int> &a2, int idx1, int idx2){
    if(a1[idx1] > a2[idx2]){
        swap(a1[idx1], a2[idx2]);
    }
}

void mergedArray(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int len = n+m;
    int gap = (len/2) + (len%2);

    while(gap > 0){
        // Place two pointers
        int left = 0;
        int right = left + gap;
        while(right < len){
            // If 1st pointer is in arr1 and 2nd pointer is in arr2
            if(left < n && right >= n){
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // If both pointers are in arr1
            else if(left < n && right < n){
                swapIfGreater(arr1, arr1, left, right);
            }
            // If both pointers are in arr2
            else if(left >= n && right >= n){
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }   
}

// Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
// Space Complexity: O(1) as we are not using any extra space.

int main()
{

    int n;
    cout << "Enter the size of first array: ";
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter the elements of first array in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size of second array: ";
    cin >> m;

    vector<int> arr2(m);
    cout << "Enter the elements of second array in sorted order: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    mergedArray(arr1, arr2, n, m);

    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}