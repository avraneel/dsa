#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a) 
{
    for(auto x : a)
        cout << x << " ";
    cout << "\n";
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
}