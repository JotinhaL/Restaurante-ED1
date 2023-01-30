#include "Stack.h"
#include "ErrorMessages.h"
#ifndef _queue_

typedef struct Queue Queue;
typedef struct Client Client;
typedef struct Command Command;
typedef struct Product Product;

struct Queue {
    Client* client;
    Queue* next;
};

struct Client
{
    char* name;
    Command* command;
    Chocolate* chocolate;
};

struct Command{
    int index;
    Product* product;
    float total;
};

struct Product {
    char* name;
    float value;
};

Queue* queue_create(int size);
int queue_push(Queue* node, Client* client);
int queue_remove(Queue* root);
int queue_free(Queue* node);

Command* command_create(int size);
int command_free(Command* node);

Product* product_create(int size);
int product_free(Product* prod);

Client* client_create(int size);
int client_free(Client *node);

#endif