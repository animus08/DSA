#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i= low; i <= high; i++){
        a[i] = temp[i - low];
    }
}

int countPairs(vector<int> &a, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && a[i] > 2 * a[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &a, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid + 1, high);
    cnt += countPairs(a, low, mid, high);
    merge(a, low, mid, high);
    return cnt;
}

int reversePairs(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}

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

    int inversions = reversePairs(a, n);
    cout << "Number of reverse pairs in the array: " << inversions << endl;
}