#include <bits/stdc++.h>
using namespace std;

vector<int> frequencyCount(vector<int> &arr)
{
    vector<int> brr;
    map<int, int> mpp;
    for (auto it : arr)
    {
        mpp[it]++;
    }

    for (int i = 1; i <= arr.size(); i++)
    {
        if (mpp.find(i) != mpp.end())
        {
            brr.push_back(mpp[i]);
        }
        else
        {
            brr.push_back(0);
        }
    }
    return brr;
}


int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    vector<int> result = frequencyCount(arr);
    for (auto it : result)
    {
        cout << it << " ";
    }
}