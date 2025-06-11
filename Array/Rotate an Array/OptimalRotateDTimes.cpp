#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int start, int end)
{
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int d;
    cin >> d;

    d = d % n;
    reverse(arr, 0, n-1);
    reverse (arr, 0, d-1);
    reverse (arr, d, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// 1 2 3 4 5
// 3 4 5 1 2 