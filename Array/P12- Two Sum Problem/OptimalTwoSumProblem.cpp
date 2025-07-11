#include <bits/stdc++.h>
using namespace std;

string twoSum(vector<int> a, int target, int n)
{
    int left = 0, right = n - 1;
    sort(a.begin(), a.end()); // Sort the array first
    while(left < right){
        int sum = a[left] + a[right];
        if(sum == target){
            return "YES";
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}

// Time Complexity: O(n log n) for sorting + O(n) for the two-pointer traversal
// Space Complexity: O(1) (not counting the input array)

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

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    string result = twoSum(a, target, n);

    if (result == "NO")
    {
        cout << "No pair found that adds up to the target." << endl;
    }
    else
    {
        cout << "Pair found that adds up to the target." << endl;
    }
}