#include<bits/stdc++.h>
using namespace std;
vector<int> intersectionSorted(vector<int> &a, vector<int> &b, int n1, int n2) {
    vector<int> ans;
    vector<int> vis (n2, 0);
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break; // Break to avoid duplicates in the intersection
            }
            if(b[j] > a[i]) {
                break; // Since both arrays are sorted, we can break early 
            }
        }
    }
    return ans;
}
// Time Complexity: O(n1 * n2) where n1 and n2 are the sizes of the two arrays.
// Space Complexity: O(n2) for the visited array in the worst case.
int main(){
    int n1, n2;

    cout << "Enter the size of first array: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter the elements of first array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter the elements of second array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    vector<int> result = intersectionSorted(a, b, n1, n2);

    cout << "Intersection of the two sorted arrays: ";
    for (int val : result)
        cout << val << " ";
}