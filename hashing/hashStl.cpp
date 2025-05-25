#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> hs;
    unordered_map<int, int> hm;

    hs.insert(5);
    hs.insert(6);

    for(int item : hs) {
        cout << item << '\n';
    }
}