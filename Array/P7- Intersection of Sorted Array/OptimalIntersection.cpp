#include <bits/stdc++.h>
using namespace std;
vector<int> intersectionSorted(vector<int> &a, vector<int> &b, int n1, int n2)
{
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n1, j < n2){
        if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else {
            // When both elements are equal, add to the intersection
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}
// Time Complexity: O(n1 + n2) where n1 and n2 are the sizes of the two arrays.
// Space Complexity: O(1) for the intersection array, not counting the output array.
int main()
{
    int n1, n2;

    cout << "Enter the size of first array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter the elements of first array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter the elements of second array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    vector<int> result = intersectionSorted(a, b, n1, n2);

    cout << "Intersection of the two sorted arrays: ";
    for (int val : result)
        cout << val << " ";
}