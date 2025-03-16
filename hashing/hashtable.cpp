#include <bits/stdc++.h>
using namespace std;

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    string name;
    int age;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hashFunction(string name) {

    unsigned int hash_value = 0;
    for(auto x : name) {
        hash_value += x;
        hash_value %= 10;
    }
    cout << "\t";
    return hash_value;
}

void initHashTable() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = nullptr;
    }
}

void printTable() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hash_table[i] == nullptr) {
            cout << i << "\t---" << "\n";
        }
        else {
            cout << i << "\t" << hash_table[i]->name << "\n";
        }
    }
}

void hashInsert(person* hashTable[], person* item) {
    int index = hashFunction(item->name);
    cout << item->name << "\t" << index << '\n';
    cout << (hashTable[index] == nullptr) << '\n';
    if(hashTable[index] == nullptr) {
        hashTable[index] = item;
    }
    else {
        cout << "Can't add as index filled\n";
    }
}

int main() {
    initHashTable();
    person ri = {name: "Richard", age: 28};
    hashInsert(hash_table, &ri);
    //cout << "Richard => " << hashFunction("Richard") << "\n";
    person ed = {name: "Edward", age: 25};
    hashInsert(hash_table, &ed);
    //cout << "Edward => " << hashFunction("Edward") << "\n";
    person su = {name: "Susan", age: 32};
    hashInsert(hash_table, &su);
    //cout << "Susan => " << hashFunction("Susan") << "\n";
    person jo = {name: "Jonathan", age: 51};
    hashInsert(hash_table, &jo);
    //cout << "Johnathan => " << hashFunction("Jonathan") << "\n";
    person ro = {name: "Ronald", age: 19};
    hashInsert(hash_table, &ro);
    //cout << "Ronald => " << hashFunction("Ronald") << "\n";
    printTable();
}