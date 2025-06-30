#include<bits/stdc++.h>
using namespace std;
vector<int> unionSorted(vector<int> arr1, vector<int> arr2, int n1, int n2)
{
    set<int> unionSet; // Using a set to store unique elements
    for (int i = 0; i < n1; i++)
    {
        unionSet.insert(arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        unionSet.insert(arr2[i]);
    }

    for (auto it : unionSet)
    {
        cout << it << " "; // Print the unique elements in the union
    }
}
// Time Complexity: O(n1log(n1) + n2log(n2)) + O(n1 + n2) for inserting elements into the set.
// Space Complexity: O(n1) + O(n2) + O(n1 + n2) for the set to store unique elements.
int main()
{
    int n1, n2;

    cout << "Enter the size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter the elements of first array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter the elements of second array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    cout << "Union of the two sorted arrays: ";
    unionSorted(arr1, arr2, n1, n2);
}