#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlapping(vector<vector<int>> &a, int n){
    sort(a.begin(), a.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        int start = a[i][0];
        int end = a[i][1];

        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int  j =i+1; j < n; j++){
            if(end >= a[j][0]){
                end = max(end, a[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// Time Complexity: O(nlogn) + O(2n)
// Space Complexity: O(n)

int main(){
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2));
    cout << "Enter the intervals (start and end): " << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    vector<vector<int>> result = mergeOverlapping(a, n);

    cout << "Merged intervals are: " << endl;
    for(int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << ", " << result[i][1] << "]" << endl;
    }
}