#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &a, int n)
{
    vector<int> ans;
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[a[i]]++;
        if(mpp[a[i]] > n/3){
            ans.push_back(a[i]);
        }
    }
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

    vector<int> result = majorityElement(a, n);
    cout << "The majority elements are: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}