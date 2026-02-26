#include <stdio.h>
#include <stdlib.h>


#define INT_ELEM 1
#define FLOAT_ELEM 2

struct list {
    struct element* head;
    int type;
};

struct element {
    union {
        int i;
        float f;
    };
    struct element* next;
};

struct list* init(int type) {
    struct list* l= malloc(sizeof(struct list));
    l->type = type;
    l->head = NULL;
    return l;
};

void insert(struct list* l, struct element* e) {
    e->next = l->head;
    l->head = e;
}

void print(struct list* l) {
    struct element* current = l->head;
    while (current != NULL) {
        if (l->type == INT_ELEM) {
           printf("%d\n", current->i);
        } else {
           printf("%f\n", current->f);
        }
        current = current -> next;
    }
}

void stat(struct list* l) {
    struct element* current = l->head;
    union {
        float f;
        int i;
    } sum;
    int n;
    sum.f = 0;
    sum.i = 0;
    n = 0;
    while (current != NULL) {
        if (l->type == INT_ELEM) {
          sum.i += current->i;
        } else {
          sum.f += current->f;
        }
        current = current -> next;
        n++;
    }
    if (n  > 0) {
        if (l->type == INT_ELEM) {
            printf("TOTAL=%d\n", sum.i);
            printf("AVG=%d\n", sum.i / n);

        } else {
            printf("TOTAL=%f\n", sum.f);
            printf("AVG=%f\n", sum.f / n);
        }
    }
}

void main() {
   struct list* l;
   struct element* e;
   
   l = init(INT_ELEM);
   
   e = malloc(sizeof(struct element));
   e->i = 3;
   insert(l, e);

   e = malloc(sizeof(struct element));
   e->i = 10;
   insert(l, e);

   print(l);
   stat(l);

   l = init(FLOAT_ELEM);
   
   e = malloc(sizeof(struct element));
   e->f = 2.4;
   insert(l, e);

   e = malloc(sizeof(struct element));
   e->f = 2.6;
   insert(l, e);

   print(l);
   stat(l);
}