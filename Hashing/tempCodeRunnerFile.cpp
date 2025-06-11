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

    vector<bool> counted(n, false); 

    for (int i = 0; i < n; i++)
    {
        if (counted[i])
            continue; 

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                counted[j] = true; 
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }

    return 0;
}
