#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeating(vector<int> &a){
    long long n = a.size();
    int missing = -1, repeating  = -1;

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(a[j] == i){
                cnt++;
            }
        }
        if(cnt == 0){
            missing = i;
        }
        if(cnt == 2){
            repeating = i;
        }
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {missing, repeating};
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> result = findMissingAndRepeating(arr);
    cout << "Missing Number: " << result[0] << endl;
    cout << "Repeating Number: " << result[1] << endl;
}