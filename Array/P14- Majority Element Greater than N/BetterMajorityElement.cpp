#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &a, int n)
{
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[a[i]]++;
    }
    for(auto it: mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1; // If no majority element found
}

// Time Complexity: O(n)+ O(nlogn) 
// Space Complexity: O(n) (for the map)

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = majorityElement(a, n);
    cout << "Majority Element: " << result << endl;
    return 0;
}