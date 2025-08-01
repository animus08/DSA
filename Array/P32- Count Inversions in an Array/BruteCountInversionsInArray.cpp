#include<bits/stdc++.h>
using namespace std;

int countInversions(vector<int> &a, int n){
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                cnt++;
            }
        }
    }
    return cnt; 
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int inversions = countInversions(a, n);
    cout << "Number of inversions in the array: " << inversions << endl;
}