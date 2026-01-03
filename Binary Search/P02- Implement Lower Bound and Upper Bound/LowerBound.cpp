// Lower Bound- This code implements the lower bound function using binary search to find the first index 
// where the target value can be inserted without violating the order of the array.

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n; // Initialize ans to n, which is out of bounds for valid indices

    while(low <= high){
        int mid = low + (high-low) / 2;
        if(a[mid] >= target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int target;
    cout<<"Enter the target elements: ";
    cin >> target;

    int ans = lowerBound(a,n,target);
    if(ans == n){
        cout << "No element found greater than or equal to " << target << endl;
    } else {
        cout << "The lower bound of " << target << " is at index: " << ans << endl;
    }
}
