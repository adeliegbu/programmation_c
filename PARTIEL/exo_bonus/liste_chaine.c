#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
    struct point* next;
};

struct point* allocate_graph(int fact) {
    struct point* first = malloc(sizeof(struct point));
    struct point* second = malloc(sizeof(struct point));
    struct point* third = malloc(sizeof(struct point));
 
    first -> x = 10*fact;
    //(*first).x = 10*fact;
    first -> y = 15*fact;
    first -> next = second;
    
    second -> x = 12*fact;
    second -> y = 14*fact;
    second -> next = third;

    third -> x = 17*fact;
    third -> y = 6*fact;
    third -> next = NULL;

    return first;
}

void print__graph(struct point* graph){
    struct point* current = graph;

    while (current != NULL) {
        printf("(%d,%d)\n", current->x, current->y);
        current = current -> next;
    }
}

void free_graph(struct point* graph) {
    struct point* current = graph;

    while (current != NULL) {
        void* tofree = current;
        current = current -> next;
        free(tofree);
    }
}

int main() {
    struct point* g;
    g = allocate_graph(2);
    print__graph(g);
    free_graph(g);
    g = allocate_graph(5);
    print__graph(g);
    free_graph(g);

    return 0;
}