#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutive(vector<int> &a, int n){
    unordered_set<int> st;
    int maxi = -1;
    
    for(int i=0; i<n ; i++){
        st.insert(a[i]); // Insert all elements into the set
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                cnt +=1;
                x += 1; // Increment x to find the next consecutive element
            }
            maxi = max(maxi, cnt); // Update maximum count
        }
    }

}

// Time Complexity: O(n) for inserting elements and O(n) for checking consecutive elements
// Space Complexity: O(n) for the unordered set
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