#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2, gcd = 1;
    cin >> n1 >> n2;

    // Best Optimized Approach
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        cout << n2;
    else
        cout << n1;


    // Not Optimised M-1-
    // for(int i=1; i<=min(n1,n2); i++){
    //     if(n1%i==0 && n2%i==0){
    //         gcd=i;
    //     }
    // }
    // Not Optimised M-2-
    // for(int i=min(n1,n2); i>=1; i--){
    //     if(n1%i==0 && n2%i==0){
    //         gcd=i;
    //         break;
    //     }
    // }

    // cout<<gcd;
}