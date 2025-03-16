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

// Take 2 pointers i and j. Initially, j at 0 and i at j - 1.
// If j finds an element less than pivot, increment i and then swap a[i] and a[j].
// Do this till j is at 2nd last element. Then exit loop and swap a[i+1] and a[high]
int partition(vector<int>& a, int low, int high) {
    // Choose pivot
    int pivot = a[high];

    // Index of smaller element and indicates the correct position of
    // pivot so far
    int i = low - 1;

    // Traverse the array
    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    // After traversal is done, i+1 will have the correct position for pivot.
    // So replace that position with pivot position
    // NOTE: Use a[high] and not pivot here because pivot is a variable only contain the value itself
    // whereas a[high] will ensure a[high] = a[i+1] proper swapping takes place.
    swap(a[i+1], a[high]);

    return i+1;     // return index of pivot
}

// Recursively sort the subdivided arrays
// Base case = subarray is 1 element long; already sorted
void quicksort(vector<int>& a, int low, int high) {

    // This if statement acts as base case. As low==high means -> 1 element array which is sorted
    if(low < high) {

        // Initially call partition for first time
        // pi = Pivot Index
        int pi = partition(a, low, high);

        // 
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