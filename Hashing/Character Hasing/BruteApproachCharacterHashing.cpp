#include <bits/stdc++.h>
using namespace std;
int f(char c, string s, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    string s = "abcdabefc";
    int size = s.length();
    // Find how many times 1 is there
    cout << "No. of a's in the above array is: " << f('a', s, size);
}
