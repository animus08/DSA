#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 4, 4, 5};
    int n = arr.size();

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    // The set will automatically handle duplicates, so we can directly use it.
    for (auto it : st)
    {
        cout << it << " ";
    }

    
    // int index = 0;
    // for (int it : st)
    // {
    //     arr[index] = it;
    //     index++;
    // }
    
    // for (int i = 0; i < index; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}