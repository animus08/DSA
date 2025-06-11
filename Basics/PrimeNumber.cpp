#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n / i != i)
            {
                count++;
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     if(n%i==0){
    //         count++;
    //     }
    // }

    if (count == 2)
    {
        cout << "No. is prime";
    }
    else
    {
        if (n == 1)
        {
            cout << "Neither Prime nor Compostie";
        }
        else
        {
            cout << "No. is not prime";
        }
    }
}
