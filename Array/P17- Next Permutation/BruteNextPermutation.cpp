// In this code we wil be using brute force approach to find the next permutation of an array.
// 1. Genarte all permutations of the array using recursion.
// 2. Sort the permutations lexicographically.
// 3. Find the current permutation using Linear Search in the sorted list and return.

#include <bits/stdc++.h>
using namespace std;

void getPerms(vector<int> &a, int index, vector<vector<int>> &ans)
{
    if (index == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = index; i < a.size(); i++)
    {
        swap(a[index], a[i]);        // Swap the current index with the loop index
        getPerms(a, index + 1, ans); // Recur for the next index
        swap(a[index], a[i]);        // Backtrack to restore the original array
    }
}

vector<vector<int>> permute(vector<int> &a)
{
    vector<vector<int>> ans;
    getPerms(a, 0, ans);
    sort(ans.begin(), ans.end()); // Sort the array to handle duplicates
    return ans;
}

vector<int> nextPermutation(vector<int> &a)
{
    vector<vector<int>> allPerms = permute(a);
    int idx = -1;
    for(int i=0; i<allPerms.size(); i++){
        if(allPerms[i] == a){
            idx = i;
            break;
        }
    }
    if (idx == -1 || idx == allPerms.size() - 1)
    {
        return allPerms[0]; // if current is last permutation or not found
    }
    else{
        return allPerms[idx + 1]; // Return the next permutation
    }
    
}

// Time Complexity: O(n! * n log n) for generating all permutations and sorting them
// Space Complexity: O(n! * n) for storing all permutations

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

    vector<int> nextPerm = nextPermutation(a);

    cout << "Next permutation is: ";
    for (int val : nextPerm)
    {
        cout << val << " ";
    }
    cout << endl;
}