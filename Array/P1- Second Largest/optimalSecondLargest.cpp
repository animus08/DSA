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

    int largest = arr[0];
    int sLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
            
        }
        else if (arr[i] > sLargest && arr[i] != largest){
                
                {
                    sLargest = arr[i];
                }
        }
    }

    cout << largest << endl;
    cout << sLargest;
}
