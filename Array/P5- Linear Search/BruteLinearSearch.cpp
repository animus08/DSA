#include <bits/stdc++.h>
using namespace std;

vector<int> linearsearch(vector<int> a, int n, int key)
{
    int i;
    for (i = 0; i <n; i++)
    {
        if(a[i] == key)
        {
            cout << "Element found at index: " << i << endl;
            return a; 
        }
    }
    cout << "Element not found in the array." << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";    
    cin >> n;

    vector<int> arr (n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    vector<int> ans = linearsearch(arr, n, key);
}
