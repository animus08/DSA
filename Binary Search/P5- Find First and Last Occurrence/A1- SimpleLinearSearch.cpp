#include<bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastOccurrence(vector<int> a, int n, int k){
    int first = -1, last = -1;
    for(int i = 0; i<n; i++){
        if(a[i] == k){
            if(first == -1)
                first = i;
            last = i;
        }
    }
    return {first, last};
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cout << "Enter the target elements: ";
    cin >> target;

    pair<int, int> ans = firstAndLastOccurrence(a, n, target);
    if (ans.first == -1)
    {
        cout << "Element not found in the array." << endl;
    }
    else
    {
        cout << "First occurrence of " << target << " is at index: " << ans.first << endl;
        cout << "Last occurrence of " << target << " is at index: " << ans.second << endl;
    }
}
