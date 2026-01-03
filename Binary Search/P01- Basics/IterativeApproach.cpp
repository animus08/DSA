#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low) / 2; // To avoid overflow
        if(arr[mid]== target){
            return mid;
        }
        else if(target > arr[mid]){
            low = mid + 1;
        }
        else{
            high  = mid - 1;
        }
    }
    return -1; // Element not found
}

// Time Complexity: O(n)
// Space Complexity: O(1)

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}
