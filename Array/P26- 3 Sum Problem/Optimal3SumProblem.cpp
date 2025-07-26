#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &a, int n)
{
    vector<vector<int>> ans;
    for(int i =0; i < n; i++){
        if(i>0 && a[i] == a[i-1]) continue;
        int j = i + 1, k = n-1;
        while(j<k){
            int sum = a[i] + a[j] +  a[k];
            if(sum < 0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                ans.push_back({a[i], a[j], a[k]});
                j++;
                k--;
                while(j<k && a[j] == a[j+1]) j++; // skip duplicates
                while(j<k && a[k] == a[k-1]) k--; // skip duplicates
            }
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