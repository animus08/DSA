#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1) // If there are no zeros, return the original array
        return a;
    
        for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap (a[i], a[j]);
            j++;
        }
    }
    return a;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();
    vector<int> ans = moveZeros(n, arr);

    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}