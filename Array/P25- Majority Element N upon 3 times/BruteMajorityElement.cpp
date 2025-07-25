#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &a, int n){
    vector<int> ans;
    for(int i =0; i<n; i++){
        if(ans.size() == 0 || ans[0] != a[i]){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(a[i] == a[j]){
                    cnt++;
                }
            }
            if(cnt > n/3){
                ans.push_back(a[i]);
            }
        }
        if(ans.size() == 2){
            break;
        }
    }
    if(ans.size() > 0){
        return ans;
    }
    else{
        return {-1};
    }
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    vector<int> result = majorityElement(a, n);
    cout << "The majority elements are: ";
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}