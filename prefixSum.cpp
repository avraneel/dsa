#include <bits/stdc++.h>
using namespace std;


void print(vector<int> &a) {
    for(auto item: a) {
        cout << item << " ";
    }
}

/* Naive approach: pfs[i] = sum(a[i] + a[i-1] + ... + a[0])*/
vector<int> prefixSumNaive(vector<int> &a) {
    vector<int> pfs(a.size());

    for(int i = 0; i < pfs.size(); i++) {
        int sum = 0;
        for(int j = 0; j <= i; j++) {
            sum += a[j];
        }
        pfs[i] = sum;
    }
    cout << "Displaying:\n";
    print(pfs);
    cout << "\n";
    return pfs;
}

void input(vector<int> &a) {
    int s;
    cout << "Enter number of elements: ";
    cin >> s;
    for(int i = 0; i < s; i++) {
        int item;
        cout << "Enter element: ";
        cin >> item;
        a.push_back(item);
    }
}

int main() {
    vector<int> a;
    input(a);
    cout << "\nYour array is\n";
    print(a);
    cout << "\nDisplaying prefix sum\n";
    vector<int> pfs = prefixSumNaive(a);
    print(pfs);
}