#include <bits/stdc++.h>
using namespace std;

int findSqrt(int n){
    int ans = 0;
    for(int i= 1; i<n; i++){
        if(i*i <= n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int result = findSqrt(n);
    cout << "The square root of " << n << " is/nearly about: " << result << endl;
}
