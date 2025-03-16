#include <stdlib.h>

typedef struct list {
    int item;
    struct list *next;
} list;

list *search_list(list *l, int x) {
    if(l == NULL) {     
        return NULL;
    }

    if(l->item == x) {
        return l;
    }
    else {
        return(search_list(l->next,x));
    }
}

// Insertion at the head 
void insert_list(list **l, int x) {
    list *p;    // temporary pointer

    p = malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;

}

void main() {

}