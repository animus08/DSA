#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &a, int n)
{
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, a[i]);
    }
    return maxVal;
}

int findMin(vector<int> &a, int n)
{
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minVal = min(minVal, a[i]);
    }
    return minVal;
}

bool possible(vector<int> &a, int day, int m, int k, int n)
{
    int cnt = 0, bouquets = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= day)
        {
            cnt++;
        }
        else
        {
            bouquets += (cnt / k);
            cnt = 0; // Reset count for the next segment
        }
    }
    bouquets += (cnt / k); // Count bouquets from the last segment
    if (bouquets >= m)
        return true;
    else
        return false;
}

int minDaysToMakeBouquets(vector<int> &a, int n, int m, int k)
{
    int mini = findMin(a, n);
    int maxi = findMax(a, n);

    if (n < (m * k))
        return -1; // Not enough flowers to make m bouquets

    for (int i = mini; i <= maxi; i++)
    {
        int bouquets = possible(a, i, m, k, n);
        if (bouquets == true)
            return i; // Return the first day that allows making m bouquets
    }
    return -1; // If no valid day found
}

int main()
{
    int n;
    cout << "Enter the number of flowers: ";
    cin >> n;
    cout << endl;

    vector<int> arr(n);
    cout << "Enter the number of flowers in each garden: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    int m;
    cout << "Enter the number of bouquets to make: ";
    cin >> m;
    cout<<endl;

    int k;
    cout << "Enter the number of flowers needed for each bouquet: ";
    cin >> k;
    cout << endl;
    
    int result = minDaysToMakeBouquets(arr, n, m, k);
    if (result != -1)
    {
        cout << "The minimum number of days to make " << m << " bouquets is: " << result << endl;
    }
    else
    {
        cout << "It's not possible to make " << m << " bouquets with the given flowers." << endl;
    }
}
