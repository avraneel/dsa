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

/* Approach 2: prefix[i] = prefix[i-1] + a[i] */
void prefixSum2(vector<int> &a) {
    vector<int> prefix(a.size());
    prefix[0] = a[0];
    for(int i = 1; i < a.size(); i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    cout << "\n2nd approach:\n";
    print(prefix);
    cout << "\n";
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
    prefixSum2(a);
}