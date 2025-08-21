#include<bits/stdc++.h>
using namespace std;

int sumByDivisor(vector<int>& a, int n, int div) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(a[i]) / div);
    }
    return sum;
}

int findSmallestDivisor(vector<int> &a, int n, int threshold){
    int maxi = *max_element(a.begin(), a.end());
    for(int i = 1; i<= maxi; i++){
        int sum = 0;
        sum = sumByDivisor(a, n, i);
        if(sum <= threshold){
            return i;
        }
    }
    return -1; // If no divisor found
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int threshold;
    cout << "Enter the threshold value: ";
    cin >> threshold;

    int result = findSmallestDivisor(a, n, threshold);
    if (result != -1) {
        cout << "The smallest divisor is: " << result << endl;
    } else {
        cout << "No valid divisor found." << endl;
    }
}
