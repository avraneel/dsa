/*
In Direct addressing Table, we have a value and a key with it. The value is thus stored at index key in the array.
We can choose not to store keys, but how will we then ensure that element its empty? For that we need custom data types.
Now I need to make array of item pointers, so I can check for NULL pointer.
*/

#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct {
    int key;
    int value;
} item;

item* direct_addressing_table[TABLE_SIZE];

/* if we keep item i without pointers, then it will become pass by value so a local copy will be created for parameter. Now, when we pass 12, that local copy will be overwritten. That's why we pass item* i as we create the address locations separately.*/
void store_value(item* i) {
    direct_addressing_table[i->key] = i;
}

bool is_empty(int key) {
    return (direct_addressing_table[key] == NULL) ? true : false;
}

void find_max() {
    int max = -999;
    int maxind = 0;
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(!is_empty(i) && direct_addressing_table[i]->value > max) {
            max = direct_addressing_table[i] -> value;
            maxind = i;
        }
    }
    printf("The maximum value is T[%d] = %d\n", maxind, max);
}

void print_value(int key) {
    if(is_empty(key) == false)
    {
        int value = direct_addressing_table[key]->value;
        printf("T[%d] = (0x%p) -> (%d,%d)\n", key, direct_addressing_table[key], key, value);
    }
    else 
        printf("T[%d] is Empty\n", key);
}

int main(void) {
    item i1 = {5, 39};
    item i2 = {12, 56};
    item i3 = {3, 21};
    store_value(&i1);
    store_value(&i2);
    store_value(&i3);
    print_value(5);
    print_value(12);
    print_value(4);
    print_value(3);
    print_value(5);
    print_value(6);
    find_max();

}
