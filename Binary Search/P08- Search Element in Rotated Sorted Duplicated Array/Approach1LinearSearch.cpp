#include<bits/stdc++.h>
using namespace std;

bool searchElement(vector<int> &arr, int n, int k){
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            return true;
            break;
        }
    }
    return false;
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
    cout << "Enter the target element: ";
    cin >> target;

    bool found = searchElement(a, n, target);
    if (found)
    {
        cout << "Element found in the array." << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
}
