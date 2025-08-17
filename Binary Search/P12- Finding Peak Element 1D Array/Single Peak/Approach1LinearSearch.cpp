#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr, int n){

    for(int i=0; i<n; i++){
        if((i == 0 || arr[i] > arr[i-1]) && 
           (i == n-1 || arr[i] > arr[i+1])){
            return arr[i]; // Found a peak element
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int peakElement = findPeakElement(a, n);
    cout << "The peak element in the array is: " << peakElement << endl;
}
