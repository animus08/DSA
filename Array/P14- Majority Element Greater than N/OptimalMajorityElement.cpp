#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &a, int n)
{
    int cnt = 0;
    int element;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            element = a[i];
            cnt = 1;
        }
        else if (a[i] == element){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i = 0; i<n; i++){
        if(a[i] == element){
            cnt1++;
        }
    }
    if(cnt1 > n/2){
        return element;
    }
    else{
        return -1; // If no majority element found
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1) (not counting the input array)

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = majorityElement(a, n);
    cout << "Majority Element: " << result << endl;
    return 0;
}