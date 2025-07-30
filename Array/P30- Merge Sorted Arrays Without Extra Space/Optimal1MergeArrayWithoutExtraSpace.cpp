#include <bits/stdc++.h>
using namespace std;

void mergedArray(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int left = n-1, right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

// Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
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