#ifndef _stack_
#include "ErrorMessages.h"

#ifndef _chocolate_
typedef struct Stack Stack;
typedef struct Chocolate Chocolate;
typedef struct Product Product;

// struct que referencia o objeto chocolate;
struct Chocolate {
    char* chocolate;
};

// struct que referencia o objeto pilha;
struct Stack {
    Chocolate* chocolate;
    Stack* next;
};
#endif

Stack* stack_create(int size);
int stack_remove(Stack* root);
int stack_push(Stack* root, Chocolate* node);
int stack_remove(Stack* root);
int stack_free(Stack* node);

Chocolate* chocolate_create(int size);
int chocolate_free(Chocolate* node);

#endif