/* Hash  Table Implementation in C++ */

#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int key;
    int value;
} item;

/* Simple mod function, transforms key K to put it in index ind of hashtable*/
int hashFunction(int key) {
    int ind = key % 20;
    return ind;
}

// vector<item*> means vector of item pointers
void storeItem(vector<item*> &ht, item *i) {
    int ind = hashFunction(i->key); // In case of DAT, ind = key, we dont use a hash function
    ht.at(ind) = i;
}

bool isEmpty(vector<item*> &ht, int key) {
    int ind = hashFunction(key);
    if (ht.at(ind) == nullptr)
        return true;
    else
        return false; 
}

void print(vector<item*> &ht) {
    for(int i = 0; i < ht.size(); i++) {
        if (ht.at(i) == nullptr) 
            cout << "HT[" << i << "]\t=\tnull\n";
        else 
            cout << "HT[" << i << "]\t=\t(" << ht.at(i) << ") -> [K=" << ht.at(i)->key << ",V=" << ht.at(i)->value <<"]\n"; 
    }
}

int main() {
    vector<item*> hashTable(20);
    item i1 = {45, 689};
    item i2 = {4353, 352};
    storeItem(hashTable, &i1);
    storeItem(hashTable, &i2);
    print(hashTable);
}