#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlapping(vector<vector<int>> &a, int n)
{
    sort(a.begin(), a.end());
    vector<vector<int>> ans;

    for(int  i =0; i < n; i++){
        if(ans.empty() || ans.back()[1] < a[i][0]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], a[i][1]);
        }
    }

    return ans;
}

// Time Complexity: O(nlogn) + O(n)
// Space Complexity: O(n)

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2));
    cout << "Enter the intervals (start and end): " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    vector<vector<int>> result = mergeOverlapping(a, n);

    cout << "Merged intervals are: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]" << endl;
    }
}