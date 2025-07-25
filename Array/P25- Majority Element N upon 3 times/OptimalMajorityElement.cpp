#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &a, int n)
{
    int cnt1 = 0, cnt2 = 0, ele1, ele2;
    for(int i =0; i <n; i++){
        if(cnt1 ==0 && a[i] != ele2){
            ele1 = a[i];
            cnt1 = 1;;
        }
        else if(cnt2 == 0 && a[i] != ele1){
            ele2 = a[i];
            cnt2 = 1;
        }
        else if(a[i] == ele1){
            cnt1++;
        }
        else if(a[i] == ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(a[i] == ele1){
            cnt1++;
        }
        else if(a[i] == ele2){
            cnt2++;
        }
    }
    if(cnt1 > n/3){
        ans.push_back(ele1);
    }
    if(cnt2 > n/3){
        ans.push_back(ele2);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> result = majorityElement(a, n);
    cout << "The majority elements are: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}