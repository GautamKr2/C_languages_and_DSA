#include <stdio.h>
#include <stdlib.h>

// Structure for B-Tree of order 3
// Maximum children = 3, and maximum key = (3-1) = 2
// Minimum children 
typedef struct node {
    int arr[2];
    struct node *left, *middle, *right;
} Node;

int main() {
    
    return 0;
}