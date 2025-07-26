#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &a, int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third  = -(a[i]+a[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {a[i], a[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(a[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> result = threeSum(a, n);
    cout << "The triplets are: ";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}