#include<bits/stdc++.h>
using namespace std;
vector<int> unionSorted(vector<int> arr1, vector<int> arr2, int n1, int n2)
{
    vector<int> unionArr;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    // If one of the arrays is exhausted, add remaining elements from the other array
    while(i < n1){
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j < n2){
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
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

    vector<int> result = unionSorted(arr1, arr2, n1, n2);

    cout << "Union of the two sorted arrays: ";
    for (int val : result)
        cout << val << " ";
}