#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutive(vector<int> &a, int n)
{
    int cnt = 0;
    int lastSamller = INT_MIN; // Initialize longest to the smallest integer
    int maxi = -1; // Initialize maximum count to -1

    sort(a.begin(), a.end()); // Sort the array to handle consecutive elements
    for(int i=0; i<n; i++){
        if (a[i] - 1 == lastSamller)
        {
            cnt++;
            lastSamller = a[i];
        }
        else if (a[i] != lastSamller)
        {
            lastSamller = a[i];
            cnt = 1; // Reset count for a new sequence
        }
        maxi = max(maxi, cnt); // Update maximum count
    }
    return {maxi}; // Return the maximum count as a vector
}

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) for the count and lastSamller variables

int main()
{
    int n;
    cout << "Enter the no. of elements in an array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements in an array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> result = longestConsecutive(a, n);
    cout << "The longest Consecutive of an Array is: " << result[0] << endl;
}