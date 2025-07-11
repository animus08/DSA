#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> a, int target, int n){
    vector<int> result;
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum = a[i]+a[j];
            if(sum == target){
                cout<<"Pair found" << endl;
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1) (not counting the output vector)
int main(){
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = twoSum(a, target, n);

    if (result.empty())
    {
        cout << "No pair found that adds up to the target." << endl;
    }
    else
    {
        cout << "Indices of the two numbers that add up to the target: ";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}