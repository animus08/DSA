#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &a, int n, int k)
{
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        int missing  = a[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return k + low;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthPositive(a, n, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;
}
