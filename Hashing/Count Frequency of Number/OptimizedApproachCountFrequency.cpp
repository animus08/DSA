#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mpp;

    for (auto it : arr)
    {
        mpp[it]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }
}
