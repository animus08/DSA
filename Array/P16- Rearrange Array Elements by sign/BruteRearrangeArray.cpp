#include<bits/stdc++.h>
using namespace std;

vector<int>  rearrangeArray(vector<int> &a, int n)
{
    vector<int> pos, neg;

    for(int i = 0; i<n; i++){
        if(a[i]>0){
            pos.push_back(a[i]);
        }
        else if(a[i]<0){
            neg.push_back(a[i]);
        }
    }

    for(int i=0; i<n/2; i++){
        a[i*2] = pos[i]; // Place positive numbers at even indices
        a[i*2 + 1] = neg[i]; // Place negative numbers at odd indices
    }

    // We can also do by this method, but it is not optimal than upper one...
    // for(int i = 0; i<n; i++){
    //     if(i%2 ==0){
    //         a[i] = pos[i/2];
    //     }
    //     else{
    //         a[i] = neg[i/2];
    //     }
    // }

    return a;
}

// Time Complexity: O(n)+O(n/2) 
// Space Complexity: O(n) (for the result array)

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

    vector<int> result = rearrangeArray(a, n);
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}