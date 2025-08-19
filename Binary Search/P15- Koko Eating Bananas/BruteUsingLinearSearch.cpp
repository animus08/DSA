#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> &a, int n){
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++){
        maxVal = max(maxVal, a[i]);
    }
    return maxVal;
}

int findTotalHours(vector<int> &a, int n, int hour){
    int totalHours = 0;
    for(int i = 0; i < n; i++){
        totalHours += ceil((double)a[i] / (double)hour);
    }
    return totalHours;
}

int minEatingSpeed(vector<int> &a, int n, int h){
    int maxVal = findMax(a, n);
    int totalHours = 0;
    for(int i = 1; i < maxVal; i++){
        totalHours = findTotalHours(a, n, i);
        if(totalHours <= h){
            return i;
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of piles: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the number of bananas in each pile: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int h;
    cout << "Enter the number of hours: ";
    cin >> h;

    int result = minEatingSpeed(arr, n, h);
    cout << "The minimum eating speed is: " << result << endl;
}
