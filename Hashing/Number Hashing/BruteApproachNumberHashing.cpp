#include <bits/stdc++.h>
using namespace std;
int f(int number, int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == number)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int size = 5;
    int arr[] = {1, 2, 3, 1, 3};
    // Find how many times 1 is there
    cout << "No. of 1's in the above array is: " << f(1, arr, size);
}