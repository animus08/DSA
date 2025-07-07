#include <bits/stdc++.h>
using namespace std;
vector<int> missingNumber(vector<int> &a, int n)
{
    for(int i= 1; i < n; i++){
        bool flag = 0;
        for(int j = 0; j < n-1; j++){
            if(a[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return {i}; // If the current number i is not found in the array, return it as the missing number
        }
    }
    return {n}; // If all numbers are present, return n as the missing number
}
// Time Complexity: O(n^2) where n is the size of the array.
// Space Complexity: O(1) for the missing number, not counting the output array.
int main()
{
    vector<int> a{1, 3, 4, 5, 6, 7}; // Example array with a missing number
    int n = a.size() + 1;

    vector<int> result = missingNumber(a, n);
    cout << "Missing number in the array: " << result[0] << endl;
    return 0;
}