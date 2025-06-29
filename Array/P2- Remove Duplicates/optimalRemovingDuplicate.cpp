#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 4, 4, 5};
    int n = arr.size();

    int i=0;
    for(int j=1; j<n; j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    } 
    for(int k=0; k<i+1; k++){
        cout<<arr[k]<<" ";
    }

}