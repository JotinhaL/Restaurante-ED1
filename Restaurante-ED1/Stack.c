#include <stdlib.h>
#include "Stack.h"

// funcao de criacao do ponteiro raiz da pilha;
Stack* stack_create(int size){
    Stack* stack;

    stack = (Stack*) malloc(size * sizeof(Stack)); // alocando dinamicamente o espaco que um nó de pilha necessita;

    if(stack == NULL){ // caso esteja nulo após a alocação dinamica, então programa atingiu o limite de uso de memoria;
        return NULL;
    }
    else{
        stack->chocolate = NULL; // como é o nó raiz, nao possui um chocolate atribuido a ele;
        stack->next = NULL; // como a pilha se inicia vazia, o ponteiro se inicializa nulo;
        return stack; // retornando o ponteiro da raiz da pilha;
    }
}

//funcao para liberar o ponteiro da pilha;
int stack_free(Stack* node){
    if(node == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        free(node);
        return SUCCESS;
    }
}

// funcao para realizar a insercao do chocolate na pilha;
int stack_push(Stack* root, Chocolate* chocolate){
    if(root == NULL){ // validacao para saber se o ponteiro está devidamente alocado;
        return INVALID_NULL_POINTER;
    }
    else{
        Stack* aux = root;
        Stack* node = root->next; // obtendo o próximo nó da pilha;
        while(node != NULL){ // enquanto nao alcançar o ultimo nó da lista, que sempre apontará para nulo;
            aux = node;
            node = node->next; // obtendo o próximo ponteiro, pois ainda nao alcançou o fim da lista;
        } // o while se encerra quando chegar ao fim da pilha;
        node = (Stack*) malloc(sizeof(Stack)); // criando o nó a ser inserido na pilha;
        if(node == NULL){ // se após a tentativa de alocacao dinamica o ponteiro ser nulo, então o programa atingiu seu limite permitido de memoria;
            return OUT_OF_MEMORY;
        }else{
            node->chocolate = chocolate; // inserindo o objeto;
            node->next = NULL; // como é o ultimo nó da pilha, apontará para nulo;
            aux->next = node; // apontando o último nó da pilha para o novo último nó da pilha;

            return SUCCESS;
        }
    }
}

// funcao para remover um nó da pilha (normalmente se passa algum tipo de identificador, mas como é uma pilha, sempre será o último nó a ser removido)
int stack_remove(Stack* root){
    if(root == NULL){ // validacao se o nó passado está devidamente alocado;
        return INVALID_NULL_POINTER;
    }
    else{
        // executando um laço de repetiçao até alcancar o ultimo nó da pilha;
        Stack* node = root->next; // obtendo o próximo nó da pilha;
        Stack* aux = root;
        while(node != NULL){ // enquanto nao alcançar o ultimo nó da lista, que sempre apontará para nulo;
            aux = node;
            node = node->next; // obtendo o próximo ponteiro, pois ainda nao alcançou o fim da lista;
        } // o while se encerra quando chegar ao fim da pilha;

        if(aux->next == NULL){ // este if será acionado apenas se a lista estiver vazia;
            return EMPTY_LIST;
        }

        node = aux->next; // enviando o ultimo node para a variavel node para poder enviar para a função de liberar a memoria dinamicamente alocada;
        aux->next = NULL; // removendo a referencia de ponteiro, pois agora o penultimo nó da pilha se tornou o último;
        stack_free(node); // enviando o ponteiro para liberar a memoria alocada;

        return SUCCESS;
    }
}

// Funcoes para chocolate

Chocolate* chocolate_create(int size){
    if(size == 0){
        return NULL;
    }
    else{
        Chocolate* choco = malloc(size * sizeof(Chocolate));
        if(choco == NULL){
            return NULL;
        }
        else{
            return choco;
        }
    }
}

int chocolate_free(Chocolate* node){
    if(node == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        free(node);

        return SUCCESS;
    }
}