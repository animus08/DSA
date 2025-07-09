#include <bits/stdc++.h>
using namespace std;
vector<int> appearingOnes(vector<int> &a, int n)
{
    for(int i=0; i<n; i++){
        int num = a[i];
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(a[j] == num){
                cnt++; // Count occurrences of the current number
            }
        }
        if(cnt == 1){
            return {num}; // If the count is 1, return the number as it appears only once
        }
    }
    return {-1}; // If no number appears once, return an empty vector
}
// Time Complexity: O(n^2) where n is the size of the array.
// Space Complexity: O(1) for the appearing once number, not counting the output array.
int main()
{
    vector<int> a{1,1,2,2,3,3,4,4}; // Example array with a missing number
    int n = a.size();

    vector<int> result = appearingOnes(a, n);
    cout << "Number appearing once in an array: " << result[0] << endl;
    return 0;
}