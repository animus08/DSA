#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    int n;
    cin>>n;
    for (int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            //cout<<i<<" ";
            v.emplace_back(i);
            if(n/i != i){
                //cout<<n/i<<" ";
                v.emplace_back(n/i);
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto it:v){
        cout<<it<<" "; 
    }
}