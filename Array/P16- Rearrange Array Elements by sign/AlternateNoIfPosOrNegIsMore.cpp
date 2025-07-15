// WAP to print alternate positive and negative numbers in an array given that the 
// number of positive and negative numbers are not equal. 

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &a, int n){
    vector<int> pos, neg;

    for(int i=0; i<n; i++){
        if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else if(a[i] < 0){
            neg.push_back(a[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        for(int i = neg.size(); i< pos.size(); i++){
            a[2*i] = pos[i];
        }
    }
    else{
        for(int i = 0; i < pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        for(int i = pos.size(); i< neg.size(); i++){
            a[2*i + 1] = neg[i];
        }
    }
    return a;
}

// Time Complexity: O(n) + O(n)
// Space Complexity: O(n) (for the pos and neg arrays)

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
    
    return 0;
}