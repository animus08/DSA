#include <bits/stdc++.h>
using namespace std;

int findSqrt(int n)
{
    int ans = 0;
    int low =1, high = n;
    while(low<=high){
        int mid = (low + high) / 2;
        if(mid * mid == n){
            return mid;
        }
        if(mid * mid > n){
            high = mid - 1;
        }
        else{
            ans = mid;
            low = mid + 1;
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
