#include <stdlib.h>
#include "Queue.h"

// funcao para criar o nó raiz da fila;
Queue* queue_create(int size){
    Queue* root;

    root = (Queue*) malloc(size * sizeof(Queue)); // alocacao dinamica do nó raiz da fila;

    if(root == NULL){ // caso esteja nulo após a alocacao dinamica, entao o programa atingiu seu limite de memoria;
        return NULL;
    }else{
        root->client = NULL; // como é o nó raiz da fila, então nenhum cliente será alocado nele;
        root->next = NULL; // como esta é a funcao de criacao, ainda não possui nenhum cliente na fila;

        return root;
    }
}

//funcao para liberar a memoria alocada que o ponteiro aponta;
int queue_free(Queue* node){
    if(node == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        free(node);
        return SUCCESS;
    }
}

//funcao para inserir um novo cliente na fila;
int queue_push(Queue* root, Client* client){
    if(root == NULL || client == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        Queue* aux = root;  // obtendo a referencia da raiz;
        Queue* node = root->next; // obtendo o primeiro nó da lista;

        while(node != NULL){ // efetuando um laco de repeticao até o fim da lista;
            aux = node; // obtendo o ponteiro que aponta para o ultimo nó, para nao perder a referencia da lista;
            node = node->next; // obtendo o proximo item da lista;
        }
        node = (Queue*) malloc(sizeof(Queue)); // alocando a memoria para o ponteiro;
        if(node == NULL){ // se após a alocacao dinamica, o ponteiro ainda apontar para NULO, entao o programa atingiu seu limite de memoria;
            return OUT_OF_MEMORY;
        }else{
            node->client = client; // inserindo o client na ultima posicao da lista;
            node->next = NULL;

            aux->next = node; // apontando o antigo ultimo da fila para o atual ultimo da fila;

            return SUCCESS;
        }
    }
}

//funcao para remover um cliente da fila (normalmente têm-se uma referencia para buscar o nó, mas numa fila a remocao sempre ocorre no comeco da lista);
int queue_remove(Queue* root){
    if(root == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        Queue* node = root->next; // obtendo o primeiro cliente da fila;
        if(node == NULL){ // se a raiz apontar para nulo, entao a fila se encontra vazia;
            return EMPTY_LIST;
        }
        else{
            Queue* aux = node->next; // obtendo o segundo cliente da fila;
            root->next = aux; // apontando a primeira posicao da fila para o antigo segundo cliente;

            queue_free(node); // enviando ponteiro para liberacao de memoria alocada;

            return SUCCESS;
        }
    }
}

/* Funcoes para Product */

Product* product_create(int size){
    Product* prod;

    prod = (Product*) malloc(size * sizeof(Product));
    if(prod == NULL){
        return NULL;
    }
    else{
        return prod;
    }
}

int product_free(Product* prod){
    if(prod == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        free(prod);

        return SUCCESS;
    }
}

/* funcoes de manipulação da Comanda */

Command* command_create(int size){
    Command* root;

    root  = (Command*) malloc(size * sizeof(Command));

    if(root == NULL){
        return NULL;
    }
    else{
        root->index = 0;
        root->total = 0.0;
        root->product = product_create(size);

        return root;
    }
}

int command_free(Command* root){
    if(root == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        free(root);
        return SUCCESS;
    }
}

// Funcoes para Clientes

Client* client_create(int size){
    if(size == 0){
        return NULL;
    }
    else{
        Client* node = malloc(size * sizeof(Client));

        if(node == NULL){
            return NULL;
        }
        else{
            node->name = "";
            node->command = NULL;
            node->chocolate = NULL;

            return node;
        }
    }
}

int client_free(Client* node){
    if(node == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        free(node);

        return SUCCESS;
    }
}