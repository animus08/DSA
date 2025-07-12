#include <bits/stdc++.h>
using namespace std;

vector<int> sort012(vector<int> a, int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid], a[high]);
            high--;
        }
    }
    return a;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (not counting the input array)

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array (0s, 1s, and 2s): ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> sortedArray = sort012(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << sortedArray[i] << " ";
    }
}