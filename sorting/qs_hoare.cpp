#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a) {
    for(auto x : a)
        cout << x << " ";
    cout << "\n";
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& a, int low, int high) {
    
    int pivot = a[low];
    int left = low - 1;
    int right = high + 1;

    while(true) {

        do {
            left++;
        } while(left < pivot);

        do {
            right--;
        } while (right > pivot);

        swap(a[left], a[right]);
    } 
}

// Recursively sort the subdivided arrays
// Base case = subarray is 1 element long; already sorted
void quicksort(vector<int>& a, int low, int high) {

    if(low < high) {

        // This if statement acts as base case. As low==high means -> 1 element array which is sorted
        int pi = partition(a, low, high);

        quicksort(a, low, pi-1);
        quicksort(a, pi+1, high);
    }
}

int main() {
    int N;
    srand(time(0));
    cout << "Enter length of array = ";
    cin >> N;
    vector<int> a;
    for(int i = 0; i < N; i++ ) 
    {
        a.push_back(rand() % 100);
    }
    int low = 0;
    int high = a.size() - 1;
    print(a); 
    quicksort(a, low, high);
    print(a);
}