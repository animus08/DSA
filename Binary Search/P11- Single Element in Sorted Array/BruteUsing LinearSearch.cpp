#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int> &arr, int n)
{
    if(n==1) return arr[0]; // If there's only one element, return it directly
    for(int i = 0; i <n; i++){
        if(i == 0){
            if(arr[i] != arr[i+1]) return arr[i];
        }
        else if(i == n-1){
            if(arr[i] != arr[i-1]) return arr[n-1];
        }
        else{
            if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
        }
    }
}
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

    int singleElement = searchElement(a, n);
    cout << "The single element in the sorted array is: " << singleElement << endl;
}
