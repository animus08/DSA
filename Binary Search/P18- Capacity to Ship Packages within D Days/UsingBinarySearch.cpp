#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &a, int n, int cap)
{
    int days = 1, load = 0;
    for (int i = 0; i < n; i++)
    {
        if (load + a[i] > cap)
        {
            days = days + 1;
            load = a[i];
        }
        else
        {
            load = load + a[i];
        }
    }
    return days;
}

int leaseWeightCapacity(vector<int> &a, int n, int days)
{
    int low = *max_element(a.begin(), a.end());  // Used STL function to find max element
    int high = accumulate(a.begin(), a.end(), 0); // Used STL function to find sum of elements

    while(low <= high){
        int mid = (low + high) / 2;
        int reqDays = findDays(a, n, mid);
        if(reqDays <= days){
            high = mid - 1; // Try to find a smaller capacity
        }
        else{
            low = mid + 1; // Increase capacity
        }
    }
    return low; // Return the minimum capacity that can ship within D days
}

int main()
{
    int n;
    cout << "Enter number of packages: ";
    cin >> n;
    cout << endl;

    vector<int> a(n);
    cout << "Enter weights of packages: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;

    int days;
    cout << "Enter number of days: ";
    cin >> days;
    cout << endl;

    int result = leaseWeightCapacity(a, n, days);
    cout << "Minimum capacity to ship packages within " << days << " days is: " << result << endl;
    return 0;
}
