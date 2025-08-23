#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &a, int n, int k){
    for(int i = 0; i < n; i++){
        if(a[i] <= k) k++;
        else break;
    }
    return k;
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

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthPositive(a, n, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;
}
