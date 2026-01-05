#include <bits/stdc++.h>
using namespace std;

int findKthElement(vector<int> &arr1, vector<int> &arr2, int n1, int n2, int k)
{
    int i = 0, j = 0, cnt = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            cnt++;
            if (cnt == k)
            {
                return arr1[i];
            }
            i++;
        }
        else
        {
            cnt++;
            if (cnt == k)
            {
                return arr2[j];
            }
            j++;
        }
    }
    while (i < n1)
    {
        cnt++;
        if (cnt == k)
        {
            return arr1[i];
        }
        i++;
    }
    while (j < n2)
    {
        cnt++;
        if (cnt == k)
        {
            return arr2[j];
        }
        j++;
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
