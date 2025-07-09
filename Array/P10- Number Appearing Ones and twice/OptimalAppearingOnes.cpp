#include <bits/stdc++.h>
using namespace std;
vector<int> appearingOnes(vector<int> &a, int n)
{
    int xorr = 0;
    for(int i=0; i<n; i++){
        xorr = xorr ^ a[i];
    }
    return {xorr}; // If no number appears once, return an empty vector
}
// Time Complexity: O(N), where N = size of the array.
// Space Complexity: O(1) as we are not using any extra space.
int main()
{
    vector<int> a{1, 1, 2, 2, 3, 3, 4, 4, 5}; // Example array with a missing number
    int n = a.size();

    vector<int> result = appearingOnes(a, n);
    cout << "Number appearing once in an array: " << result[0] << endl;
    return 0;
}
