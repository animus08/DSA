#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeating(vector<int> &a)
{
    long long n = a.size();
    int hash[n+1] = {0};

    for(int i = 0; i < n; i++){
        hash[a[i]]++;
    }

    int missing  = -1, repeating  = -1;

    for(int i = 1; i <= n; i++){
        if(hash[i] == 0){
            missing  = i;
        }
        if(hash[i] == 2){
            repeating  = i;
        }
        if(missing != -1 && repeating  != -1){
            break;
        }
    }

    return {missing, repeating};
}

// Time Complexity: O(n)
// Space Complexity: O(n)

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = findMissingAndRepeating(arr);
    cout << "Missing Number: " << result[0] << endl;
    cout << "Repeating Number: " << result[1] << endl;
}