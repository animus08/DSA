#include <bits/stdc++.h>
using namespace std;
void Zeros(vector<int> &arr, int n)
{

    vector<int> temp(n, 0);

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";
}
int main()
{
    vector<int> arr = {1, 2, 0, 0, 3, 4, 5, 0};
    int n = arr.size();
    Zeros(arr, n);
}