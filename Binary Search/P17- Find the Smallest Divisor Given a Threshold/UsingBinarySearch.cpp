#include <bits/stdc++.h>
using namespace std;

int sumByDivisor(vector<int> &a, int n, int div)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)(a[i]) / div);
    }
    return sum;
}

int findSmallestDivisor(vector<int> &a, int n, int threshold)
{
    int maxi = *max_element(a.begin(), a.end());
    int low = 1, high = maxi;
    while(low <= high){
        int mid = (low + high) / 2;
        int sum = sumByDivisor(a, n, mid);
        if (sum <= threshold)
        {
            // If the sum is less than or equal to threshold, we can try smaller divisors
            high = mid - 1;
        }
        else
        {
            // If the sum is greater than threshold, we need a larger divisor
            low = mid + 1;
        }
    }
    return low; // The smallest divisor that meets the condition
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

    int threshold;
    cout << "Enter the threshold value: ";
    cin >> threshold;

    int result = findSmallestDivisor(a, n, threshold);
    if (result != -1)
    {
        cout << "The smallest divisor is: " << result << endl;
    }
    else
    {
        cout << "No valid divisor found." << endl;
    }
}
