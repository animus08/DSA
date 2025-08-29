#include <bits/stdc++.h>
using namespace std;

long double minimizeMaxDistance(vector<int> &arr, int n, int k)
{
    vector<int> howMany(n, 0);
    priority_queue<pair<long double, int>> pq;

    for(int i = 0; i < n-1; i++){
        pq.push({arr[i+1]-arr[i], i});
    }

    for(int gasStations = 1; gasStations <= k; gasStations++){
        auto tp = pq.top(); 
        pq.pop();
        int secIndex = tp.second;
        howMany[secIndex]++;
        long double diff = (arr[secIndex + 1] - arr[secIndex]);
        long double sectionLength = diff / (long double)(howMany[secIndex] + 1);
        pq.push({sectionLength, secIndex});
    }

    return pq.top().first; // The maximum distance after adding k gas stations
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
