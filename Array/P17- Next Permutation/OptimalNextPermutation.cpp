#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &a, int n)
{
    int idx = -1;
    for(int i=n-2; i>=0; i--){
        if(a[i]<a[i+1]){
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(a.begin(), a.end()); // If no such index found, reverse the entire array
        return a;
    }

    for(int i=n-1; i>idx; i--){
        if(a[i]>a[idx]){
            swap(a[idx], a[i]);
            break;
        }
    }

    reverse(a.begin()+idx+1, a.end()); // Reverse the subarray after the found index

    return a; // Return the next permutation
}

// Time Complexity- O(n)+O(n)+O(n)
// Space Complexity- O(1)

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

    vector<int> nextPerm = nextPermutation(a, n);

    cout<< "Next permutation: ";
    for (int i = 0; i < n; i++)
    {
        cout << nextPerm[i] << " ";
    }
}