#include <bits/stdc++.h>
using namespace std;

vector<int> leadersOfArray(vector<int> &a, int n)
{
    vector<int> leaders;
    int maxi = INT_MIN; // Initialize maximum to the smallest integer
    for(int i = n-1; i>=0; i--)
    {
        if (a[i] > maxi)
        {
            leaders.push_back(a[i]);
        }
        maxi = max(maxi , a[i]);
    }
    // reverse(leaders.begin(), leaders.end()); // Reverse to maintain order
    // No need to sort this as it is already sorted...
    return leaders;
}

// Time Complexity: O(N)
// Space Complexity: O(N) (only for storing the ans.)

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

    vector<int> result = leadersOfArray(a, n);
    cout << "The Leaders of an Array are: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}