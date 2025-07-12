#include<bits/stdc++.h>
using namespace std;

vector<int> sort012(vector<int>a, int n){
    
    sort(a.begin(), a.end()); // Sort the array using Standard Library sort function
    return a;
    
}

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) (not counting the input array)

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array (0s, 1s, and 2s): ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> sortedArray = sort012(a, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << sortedArray[i] << " ";
    }
}