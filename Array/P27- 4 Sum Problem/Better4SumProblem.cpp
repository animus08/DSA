#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &a, int n, int target)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashSet;
            for(int k = j+1; k<n; k++){
                long long sum = a[i] + a[j];
                sum += a[k];
                long long fourth  = target - sum;
                if(hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp = {a[i], a[j], a[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(a[k]);
            }
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

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> result = fourSum(a, n, target);

    cout << "The quadrlets are: ";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}