#include <bits/stdc++.h>
using namespace std;
vector<int> max_min(vector<int> &arr)
{
    map<int, int> mpp;
    for (auto it : arr)
    {
        mpp[it]++;
    }
    int max_freq = INT_MIN, min_freq = INT_MAX;
    int max_element, min_element;

    for (auto it : mpp)
    {
        if (it.second > max_freq)
        {
            max_freq = it.second;
            max_element = it.first;
        }
        if (it.second < min_freq)
        {
            min_freq = it.second;
            min_element = it.first;
        }
    }
    return {max_element, min_element};
}
int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    vector<int> result = max_min(arr);
    cout<<result[0]<<" "<<result[1];
}