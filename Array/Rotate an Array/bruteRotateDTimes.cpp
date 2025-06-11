#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr, int n, int d){
    int temp[n];
    int j = 0;
    for (int i = n-d; i < n; i++)
    {
        temp[i] = arr[j];           // arr[i-(n-d)]
        j++;
    }
    for (int i = d; i < n; i++)
    {
        temp[i - d] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    return;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int d ;
    cin >> d;
    
    d = d % n;
    rotate(arr, n, d);
}
