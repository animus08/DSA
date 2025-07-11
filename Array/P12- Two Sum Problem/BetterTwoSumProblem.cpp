#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> a, int target, int n){
    vector<int> result;
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int moreNum = target - a[i];
        if(mpp.find(moreNum) != mpp.end()){
            result.push_back(mpp[moreNum]);
            result.push_back(i);
            return result;
        }
        mpp[a[i]] = i; // Store the index of the current element
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n) (for the map to store elements and their indices)

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout<< "Enter the elements of the array: ";
    for(int i=0; i<n ; i++){
        cin>>a[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = twoSum(a, target, n);

    if(result.empty()){
        cout << "No pair found that adds up to the target." << endl;
    }
    else {
        cout << "Indices of the two numbers that add up to the target: ";
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
}