#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &a, int n, int pages){
    int students = 1;
    long long pagesStudents = 0;
    for(int i = 0; i < n; i++){
        if (pagesStudents + a[i] <= pages)
        {
            pagesStudents += a[i];
        }
        else{
            students++;
            pagesStudents = a[i];
        }
    }
    return students;
}

int findpages(vector<int> &a, int n, int m){
    if(n < m) return -1; // Not enough books for students
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    for(int pages = low; pages <= high; pages++){
        int students = countStudents(a,n, pages);
        if(students == m){
            return pages;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the no. of pages in each book: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int cows;
    cout << "Enter number of students: ";
    cin >> cows;
    cout << endl;
    
    int result = findpages(stalls, n, cows);
    if (result != -1)
    {
        cout << "The minimum number of pages a student has to read is: " << result << endl;
    }
    else
    {
        cout << "Not enough books for the students." << endl;
    }
}
