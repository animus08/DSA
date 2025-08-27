#include <bits/stdc++.h>
using namespace std;

long double minimizeMaxDistance(vector<int> &arr, int n, int k) {
    vector<int> howMany(n, 0);
    for (int gasStations = 1; gasStations <= k; gasStations++)
    { 
        long double maxDistance = -1;
        int maxIndex = -1;
        for(int i = 0; i < n-1; i++){
            long double diff = (arr[i+1] - arr[i]);
            long double sectionLength = diff / (long double)(howMany[i]+ 1);
            if (sectionLength > maxDistance) {
                maxDistance = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }

    long double maxAns = -1;
    for(int i = 0; i < n-1; i++){
        long double diff = (arr[i + 1] - arr[i]);
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}

int main(){
    int n;
    cout << "Enter the number of gas stations: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the positions of the gas stations: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of additional gas stations: ";
    cin >> k;

    long double result = minimizeMaxDistance(arr, n, k);
    cout << "The minimized maximum distance between gas stations is: " << fixed << setprecision(10) << result << endl;
}
