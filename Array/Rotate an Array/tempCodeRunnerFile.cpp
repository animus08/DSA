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

// void rotate(vector<int> &arr, int n, int d)
// {
//     reverse(arr, 0, d - 1);
//     reverse(arr, d, n - 1);
//     reverse(arr, 0, n - 1);
// }

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
