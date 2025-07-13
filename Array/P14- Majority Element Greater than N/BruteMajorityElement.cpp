#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &a, int n){
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(a[i] == a[j]){
                cnt++;
            }
        }
        if(cnt > n/2){
            return a[i];
        }
    }
    return -1; // If no majority element found
}

// Time Complexity: O(n^2)
// Space Complexity: O(1) (not counting the input array)

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int result = majorityElement(a, n);
    cout << "Majority Element: " << result <<endl;
    return 0;
}