#include <bits/stdc++.h>
using namespace std;
vector<int> missingNumber(vector<int> &a, int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];                    // Calculate the sum of the elements in the array
    }
    int totalSum = n * (n + 1) / 2;     // Calculate the expected sum of the first n natural numbers
    int missingNum = totalSum - sum;        
    return {missingNum};                // Return the missing number as a vector
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) for the missing number, not counting the output array.
int main(){
    vector<int> a{1, 2, 3, 5}; // Example array with a missing number
    int n = a.size() + 1;

    vector<int> result = missingNumber(a, n);
    cout << "Missing number in the array: " << result[0] << endl;
    return 0;
}