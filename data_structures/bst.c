#include <stddef.h>

typedef struct tree {
    int item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
    
} tree; 

tree *search(tree *t, int x) {
    if(t == NULL || t->item == x)
        return t;

    if(x < t->item) 
        return(search(t->left, x));
    else
        return(search(t->right, x));
}

tree *find_minimum(tree *t, int x) {
    tree *min;

    if(t == NULL)
        return NULL;

    min = t;
    while(min->left != NULL) {
        min = min->left;
    }

    return min;
}

tree *insert(tree* t, int x) {
    tree *p = malloc(sizeof(tree));

    

}


int main() {

    return 0;
}

