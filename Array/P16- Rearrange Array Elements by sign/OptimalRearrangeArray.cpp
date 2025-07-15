#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &a, int n)
{
    vector<int> result(n, 0);
    int posIndex = 0, negIndex = 1;

    for(int i=0; i<n; i++){
        if(a[i]>0){
            result[posIndex] = a[i];
            posIndex += 2; // Move to the next even index
        }
        else{
            result[negIndex] = a[i];
            negIndex += 2; // Move to the next odd index
        }
    }
    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(n) (for the result array)

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

    vector<int> result = rearrangeArray(a, n);
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}