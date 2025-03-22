/*
In Direct addressing Table, we have a value and a key with it. The value is thus stored at index key in the array.
We can choose not to store keys, but how will we then ensure that element its empty? For that we need custom data types.
Now I need to make array of item pointers, so I can check for NULL pointer.
*/

#include <stdio.h>

#define TABLE_SIZE 100

typedef struct {
    int key;
    int value;
} item;

int direct_addressing_table[TABLE_SIZE];

void store_value(int key, int value)
{
    direct_addressing_table[key] = value;
}

void print_value(int key)
{
    int value = direct_addressing_table[key];
    printf("T[%d] = %d\n", key, value);
}

int main(void) {
    store_value(5, 39);
    store_value(12, 56);
    store_value(2, 24352);
    print_value(5);
    print_value(4);
    print_value(45);
}
