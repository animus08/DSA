#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4,4,4,5};
    int n=arr.size();
    bool flag =1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>= arr[i-1]){
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    cout<<flag;
}