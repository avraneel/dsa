#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a) {
    for(auto x : a)
        cout << x << " ";
    cout << "\n";
}

// Choose the key, initially at 1. Store its value.
// Compare all elements to the left of key. If key is smaller, then rshift the element by 1.
// Do this until a[j] <= key or j < 0, then put key at j+1 position.
void insertionSort(vector<int>& a) 
{
    for(int i = 1; i < a.size(); i++) 
    {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key) 
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() 
{
    int N;
    srand(time(0));
    cout << "Enter length of array = ";
    cin >> N;
    vector<int> a;
    for(int i = 0; i < N; i++ ) 
    {
        a.push_back(rand() % 100);
    }

    print(a); 
    insertionSort(a);
    print(a);
  
}