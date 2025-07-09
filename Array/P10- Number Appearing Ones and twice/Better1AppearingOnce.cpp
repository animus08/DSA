#include <bits/stdc++.h>
using namespace std;
vector<int> appearingOnes(vector<int> &a, int n)
{
    int maxi = a[0];

    for(int i=0; i<n; i++){
        maxi = max(maxi, a[i]);
    }

    vector<int> hash(maxi + 1, 0); // Create a hash array to count occurrences of each number
    for(int i=0; i<n; i++){
        hash[a[i]]++;
    }

    for(int i=0; i<n; i++){
        if(hash[a[i]] == 1){
            return {a[i]}; 
        }
    }

    return {-1};
}
// Time Complexity: O(N)+O(N)+O(N), where N = size of the array
// One O(N) is for finding the maximum, the second one is to hash the elements and the 
// third one is to search the single element in the array.
// Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
int main()
{
    vector<int> a{1, 1, 2, 2, 3, 3, 4, 4, 5}; // Example array with a missing number
    int n = a.size();

    vector<int> result = appearingOnes(a, n);
    cout << "Number appearing once in an array: " << result[0] << endl;
    return 0;
}