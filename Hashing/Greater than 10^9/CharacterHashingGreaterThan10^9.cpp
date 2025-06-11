#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int size = s.length();

    // Pre-Compute

    map<char, int> mpp;
    for (int i = 0; i < size; i++)
    {
        mpp[s[i]]++;
    }

    // Print all hashed values using map.
    for (auto it : mpp)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    // fetch
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        cout << mpp[ch] << endl;
    }
}
