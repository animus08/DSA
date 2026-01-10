#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int r, int c, int mid) {
    int low = 0;
    int high = c-1;
    int ans = c; // Initialize ans to c, which is out of bounds for valid indices

    while(low <= high){
        int midIndex = (low + high) / 2;
        if(arr[midIndex] > mid){
            ans = midIndex;      // Update ans to the current index
            high = midIndex - 1; // Move to the left side
        }
        else{
            low = midIndex + 1; // Move to the right side
        }
    }
    return ans; // Return the first index where the element is greater than mid
}

int countSmallEqual(vector<vector<int>> &mat, int r, int c, int mid){
    int cnt = 0;
    for(int i = 0; i < r; i++){
        cnt += upperBound(mat[i], r, c, mid);
    }
    return cnt; // Count of elements less than or equal to mid
}

int median(vector<vector<int>> &mat, int r, int c)
{
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        low = min(low, mat[i][0]); // Find the minimum element
        high = max(high, mat[i][c - 1]); // Find the maximum element
    }

    int req = (r * c) / 2; // Required count of elements for median

    while(low <= high){
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(mat, r, c, mid);
        if(smallEqual <= req){
            low = mid + 1; // Move to the right side
        }
        else{
            high = mid - 1; // Move to the left side
        }
    }
    return low; // The median is the first element greater than the required count
}

int main()
{
    int r;
    cout << "Enter the number of rows in the matrix: ";
    cin >> r;

    int c;
    cout << "Enter the number of columns in the matrix: ";
    cin >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    cout << "Enter the elements of the matrix (row-wise):" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }

    int result = median(mat, r, c);
    cout << "The median of the matrix is: " << result << endl;
}
