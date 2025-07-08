#include <bits/stdc++.h>
using namespace std;
vector<int> maxConsecutiveOnes(vector<int> &a, int n)
{
    vector<int> r (n, 0); // Initialize a result vector to store counts of consecutive 1s
    int j = 0;
    for(int i =0; i<n; i++){
        if (a[i] == 1){
            r[j]++; // count consecutive 1s
        }else
        {
            j++; // move to next group on 0
        }
    }
    int largest = r[0]; // assume first element is largest

    for (int i = 1; i < j; i++)
    {
        if (r[i] > largest)
        {
            largest = r[i]; // update if a larger element is found
        }
    }

    return {largest};
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) for the result vector, not counting the output array.
int main()
{
    vector<int> a{1,1,0,1,1,1,0,1,1}; // Example array with a missing number
    int n = a.size();

    vector<int> result = maxConsecutiveOnes(a, n);
    cout << "Maximum consecutive ones in an array: " << result[0] << endl;
    return 0;
}

