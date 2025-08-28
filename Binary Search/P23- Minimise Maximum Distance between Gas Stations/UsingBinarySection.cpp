#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(vector<int> &arr, int n, long double distance){
    int cnt = 0;
    for(int i = 1; i < n; i++){
        int numberInBetween = ((arr[i] - arr[i-1]) / distance);
        if ((arr[i] - arr[i-1]) / distance == numberInBetween * distance) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimizeMaxDistance(vector<int> &arr, int n, int k)
{
    long double low = 0;
    long double high = 0;

    for(int i = 0; i < n - 1; i++){
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }

    long double diff = 1e-6; // Precision for the binary search
    while (high - low > diff) {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(arr, n, mid);
        if (cnt <= k) {
            high = mid; // Try to minimize the maximum distance
        }
        else {
            low = mid; // Increase the maximum distance
        }
    }
    return high; // The minimized maximum distance between gas stations
}

int main()
{
    int n;
    cout << "Enter the number of gas stations: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the positions of the gas stations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of additional gas stations: ";
    cin >> k;

    long double result = minimizeMaxDistance(arr, n, k);
    cout << "The minimized maximum distance between gas stations is: " << fixed << setprecision(10) << result << endl;
}
