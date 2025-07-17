#include<bits/stdc++.h>
using namespace std;

vector<int> leadersOfArray(vector<int> &a, int n){
    vector<int> leaders;
    for(int i=0; i<n; i++){
        bool flag = 1;
        for(int j=i+1; j<n; j++){
            if(a[j] >= a[i]){
                flag = 0;
                break;
            }
        }
        if(flag ==1){
            leaders.push_back(a[i]);
        }
    }
    // reverse(leaders.begin(), leaders.end()); // Reverse to maintain order
    // sort(leaders.begin(), leaders.end()); // Sort in descending order
    return leaders;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N) (only for storing the ans.)

int main(){
    int n;
    cout<<"Enter the no. of elements in an array: ";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the elements in an array: ";
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> result = leadersOfArray(a, n);
    cout<<"The Leaders of an Array are: ";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}