#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows, int n){
    int cnt = 1, last = stalls[0];
    for(int i = 1; i < n; i++){
        if(stalls[i] - last >= dist){
            cnt++;
            last = stalls[i];
        }
        if(cnt >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows, int n){
    sort(stalls.begin(), stalls.end());
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());
    for(int i = 1; i <= (maxi-mini); i++){
        if(canWePlace(stalls, i, cows, n) == true){
            continue;
        }
        else{
            return i-1;
        }
    }
}

int main(){
    int n;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the positions of the stalls: ";
    for(int i = 0; i < n; i++){
        cin >> stalls[i];
    }

    int cows;
    cout << "Enter number of cows: ";
    cin >> cows;

    int result = aggressiveCows(stalls, cows, n);
    cout << "The largest minimum distance is: " << result << endl;
}
