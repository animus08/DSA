#include <bits/stdc++.h>
using namespace std;
vector<int> missingNumber(vector<int> &a, int n)
{
    int hash[n+1]={0};
    for(int i = 0; i < n - 1; i++){
        hash[a[i]] = 1;
    }
    for(int i = 1; i < n; i++){
        if(hash[i] == 0){
            return {i}; // If the current number i is not found in the array, return it as the missing number
        }
    }
}
// Time Complexity: O(n) + O(n) = O(2n) where n is the size of the array.
// Space Complexity: O(n) for the hash array, not counting the output array.
int main()
{
    vector<int> a{1, 3, 4, 5, 6, 7}; // Example array with a missing number
    int n = a.size() + 1;

    vector<int> result = missingNumber(a, n);
    cout << "Missing number in the array: " << result[0] << endl;
    return 0;
}
