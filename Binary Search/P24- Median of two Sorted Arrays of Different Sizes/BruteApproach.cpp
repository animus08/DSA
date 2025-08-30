#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        arr3.push_back(arr1[i]);
        i++;
    }
    while (j < n2)
    {
        arr3.push_back(arr2[j]);
        j++;
    }

    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return (double)arr3[n / 2];
    }
    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
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
