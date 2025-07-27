#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &a, int n, int target)
{
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++){
        if (i > 0 && a[i] == a[i - 1]) continue; 
        for (int j = i + 1; j < n; j++){
            if (j > i + 1 && a[j] == a[j - 1]) continue; 
            int k = j + 1, l = n - 1;
            while (k < l) {
                long long sum = a[i] + a[j] + a[k] + a[l];
                if (sum < 0) {
                    k++;
                } else if (sum > 0) {
                    l--;
                } else {
                    ans.push_back({a[i], a[j], a[k], a[l]});
                    k++;
                    l--;
                    while (k < l && a[k] == a[k - 1]) k++; 
                    while (k < l && a[l] == a[l + 1]) l--;
                }
            }
        }
    }
    return ans;
}

// Time Complexity: O(n^3)
// Space Complexity: O(1) for the input array, O(k) for the output where k is the number of quadruplets found

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