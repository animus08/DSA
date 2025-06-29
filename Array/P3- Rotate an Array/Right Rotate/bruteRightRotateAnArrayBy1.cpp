#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    
    int temp[n];

    for(int i = 0; i < n-1; i++){
        temp[i + 1] = arr[i];
    }

    temp[0]=arr[n-1];

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}