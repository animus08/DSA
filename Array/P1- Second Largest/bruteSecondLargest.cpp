#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int largest = arr[n - 1];
    int sLargest = INT_MIN;
    
    for(int i=n-2; i>=0; i--){
        if(arr[i]!= largest){
            sLargest = arr[i];
            break;
        }
    }
    cout<< largest;
    cout << sLargest;
}