#include <bits/stdc++.h>
using namespace std;

void mergedArray(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    vector<long long> arr3(n+m);
    int left = 0, right = 0, index= 0;

    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++;
            index++;
        }
        else{
            arr3[index] = arr2[right];
            right++;
            index++;
        }
    }

    while(left < n){
        arr3[index] = arr1[left];
        left++;
        index++;
    }

    while(right < m){
        arr3[index] = arr2[right];
        right++;
        index++;
    }

    for(int i=0; i<(n+m); i++){
        if(i<n) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];
    }
}

// Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
// Space Complexity: O(n+m) as we use an extra array of size n+m.
int main(){

    int n;
    cout << "Enter the size of first array: ";
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter the elements of first array in sorted order: ";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size of second array: ";
    cin >> m;

    vector<int> arr2(m);
    cout << "Enter the elements of second array in sorted order: ";
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    mergedArray(arr1, arr2, n, m);

    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}