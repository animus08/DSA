#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &a, int n, int pages)
{
    int pairs = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] <= pages)
        {
            sum += a[i];
        }
        else
        {
            pairs++;
            sum = a[i];
        }
    }
    return pairs;
}

int findLargestMin(vector<int> &a, int n, int m)
{
    if (n < m)
        return -1; // Not enough books for students
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int pairs = count(a, n, mid);
        if (pairs <= m)
        {
            high = mid - 1; // Try to minimize the pages
        }
        else
        {
            low = mid + 1; // Increase the pages
        }
    }
    return low; // The minimum pages that can be allocated to a student
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cout << "Enter the number of pairs: ";
    cin >> m;

    int result = findLargestMin(a, n, m);
    if (result != -1)
    {
        cout << "The largest minimum sum that can be achieved is: " << result << endl;
    }
    else
    {
        cout << "Not enough elements to form the required pairs." << endl;
    }
}
