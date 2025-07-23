#include<bits/stdc++.h>
using namespace std;

int countSubarraySum(vector<int> &a, int n, int target){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += a[k];
            }        
            if(sum == target){
                cnt++;
            }
        }
    }
    return cnt;
}

// Time Complexity: O(N3), where N = size of the array.
// Space Complexity: O(1) as we are not using any extra space.

int main(){

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int result = countSubarraySum(a, n, target);
    cout << "Number of subarrays with sum equal to " << target << ": " << result << endl;
}