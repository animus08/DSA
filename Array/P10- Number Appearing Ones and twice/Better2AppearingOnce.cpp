#include <bits/stdc++.h>
using namespace std;
vector<int> appearingOnes(vector<int> &a, int n)
{
    map<int, int> mpp; // Create a map to count occurrences of each number
    for(int i = 0; i < n; i++){
        mpp[a[i]]++;
    }

    for(auto it : mpp){
        if(it.second == 1){
            return {it.first}; // If the count is 1, return the number as it appears only once
        }
    }
    return {-1}; // If no number appears once, return an empty vector
}
// Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
// Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
int main()
{
    vector<int> a{1, 1, 2, 2, 3, 3, 4, 4, 5}; // Example array with a missing number
    int n = a.size();

    vector<int> result = appearingOnes(a, n);
    cout << "Number appearing once in an array: " << result[0] << endl;
    return 0;
}