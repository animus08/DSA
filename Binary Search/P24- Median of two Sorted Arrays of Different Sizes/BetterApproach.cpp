#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
    int i = 0, j = 0;
    int cnt = 0;
    int n = n1 + n2;
    int idx2 = n/2;
    int idx1 = idx2 - 1;
    int ele1 = -1, ele2 = -1;

    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            if(cnt == idx1) ele1 = arr1[i];
            if(cnt == idx2) ele2 = arr1[i];
            i++;
            cnt++;
        }
        else{
            if(cnt == idx1) ele1 = arr2[j];
            if(cnt == idx2) ele2 = arr2[j];
            j++;
            cnt++;
        }
    }

    while(i < n1){
        if(cnt == idx1) ele1 = arr1[i];
        if(cnt == idx2) ele2 = arr1[i];
        i++;
        cnt++;
    }

    while(j < n2){
        if(cnt == idx1) ele1 = arr2[j];
        if(cnt == idx2) ele2 = arr2[j];
        j++;
        cnt++;
    }

    if(n % 2 == 1) {
        return (double)ele2;
    }
    return (double)((double)(ele1 + ele2)) / 2.0;
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
