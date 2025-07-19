#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &a, int n, int key){
    for(int i = 0; i<n; i++){
        if(a[i] == key){
            return true;
        }
    }
    return false;
}
vector<int> longestConsecutive(vector<int> &a, int n)
{
    int maxi = -1;
    for(int i = 0; i < n; i++)
    {
        int cnt = 1; // Count of consecutive elements
        while(linearSearch(a, n, a[i]+1) == true){
            a[i]++;
            cnt++;
        }
        maxi = max(maxi, cnt); // Update maximum count
    }
    return {maxi}; // Return the maximum count as a vector
}

// Time Complexity: O(N2)
// Space Complexity: O(1), as we are not using any extra space

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