#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "ErrorMessages.h"

int sizeof_string(char string[]);

int main(){
    Product* menu = product_create(10);

    char nomes[][20] = {
            "Sandubao",
            "X-tudo",
            "MilkShake",
            "Banana-Split",
            "Sorvete de Murango",
            "Salada",
            "Torta de Beterraba",
            "Bolo de Couve",
            "Kinder Ovo",
            "Cafe"
        };
    float valores[] = {
        1.99,
        4.00,
        9.99,
        2.50,
        12.00,
        3.50,
        7.23,
        1.95,
        2.30,
        0.50
    };

    Product* aux = product_create(1);

    char clientes[][20] = {
        "Adalberto",
        "Eute Frodo",
        "Ana Clara",
        "Maria Geovanna",
        "Jubiscleide",
        "Kreuza",
        "Jacinto Pinto",
        "Mastu brando",
        "Josefanny",
        "Anakin"
    };


    for(int i = 0; i < 10; i++){
        aux->name = nomes[i];
        aux->value = valores[i];
        menu[i] = *aux;
    }
    product_free(aux);
    
    Queue* fila = queue_create(1);

    Client c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

    c1.name = "Adalberto";
    c2.name = "Eute Frodo";
    c3.name = "Ana Clara";
    c4.name = "Maria Geovanna";
    c5.name = "Jubiscleide";
    c6.name = "Kreuza";
    c7.name = "Jacinto Pinto";
    c8.name = "Mastu brando";
    c9.name = "Josefanny";
    c10.name = "Anakin";

    queue_push(fila, &c1);
    queue_push(fila, &c2);
    queue_push(fila, &c3);
    queue_push(fila, &c4);
    queue_push(fila, &c5);
    queue_push(fila, &c6);
    queue_push(fila, &c7);
    queue_push(fila, &c8);
    queue_push(fila, &c9);
    queue_push(fila, &c10);

    Chocolate ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, ch10;
    ch1.chocolate = "Kit kat";
    ch2.chocolate = "Ouro Branco";
    ch3.chocolate = "Lollo";
    ch4.chocolate = "Sonho de Valsa";
    ch5.chocolate = "Diamante Negro";
    ch6.chocolate = "Crocante";
    ch7.chocolate = "Prestigio";
    ch8.chocolate = "Alpino";
    ch9.chocolate = "Chokito";
    ch10.chocolate = "Trufa da Cacau Show";

    Stack* chocolates = stack_create(10);

    stack_push(chocolates, &ch1);
    stack_push(chocolates, &ch2);
    stack_push(chocolates, &ch3);
    stack_push(chocolates, &ch4);
    stack_push(chocolates, &ch5);
    stack_push(chocolates, &ch6);
    stack_push(chocolates, &ch7);
    stack_push(chocolates, &ch8);
    stack_push(chocolates, &ch9);
    stack_push(chocolates, &ch10);

    Queue *cliente = queue_create(1);
    cliente = fila->next;
    Stack* choco = stack_create(1);
    choco = chocolates->next;

    int i = 0;
    while (cliente != NULL)
    {
        cliente->client->command = command_create(i+1);
        for(int j = 0; j <= i; j++){
           cliente->client->command->product[j] = menu[j];
           cliente->client->command->total += menu[j].value;
        }
        cliente->client->chocolate = choco->chocolate;

        cliente = cliente->next;
        choco = choco->next;
        i++;
    }

    queue_free(cliente);
    stack_free(choco);

    Queue* aux2 = fila->next;
    i = 0;
    while(aux2 != NULL){
        printf("Cliente: %s\n", aux2->client->name);
        printf("Comanda: \n");
        for(int j = 0; j <= i; j++){
            printf("%s ", aux2->client->command->product[j].name);
            for(int k = sizeof_string(aux2->client->command->product[j].name); k < 50; k++){
                printf("-");
            }
            printf(" %.2f\n",aux2->client->command->product[j].value);
        }
        printf("---------------------------------------------------------\n");
        printf("Total ------------------------------------------ R$ %.2f\n", aux2->client->command->total);
        printf("Apos o pagamento, o cliente %s recebeu o bombom: %s\n\n\n", aux2->client->name, aux2->client->chocolate->chocolate);
        printf("\n\n\n\n");
        aux2 = aux2->next;
        i++;
    }

    queue_free(aux2);

    queue_free(fila);
    stack_free(chocolates);
    product_free(menu);

    return SUCCESS;
}

// funcao auxiliar para contagem de caracteres, para formatar a saida da comanda;
int sizeof_string(char string[]){
    int count = 0;

    char c = string[count];
    while(c != '\0'){
        count++;
        c = string[count];
    }

    return count;
}