#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *description;
    int ticketQuantity;
    int ID;
} Event;

void registerEvent(Event *schedule, int *cont, int *i);
void updateEvent(Event *schedule, int cont);
void search(Event schedule[], int cont);
void list(Event schedule[], int cont);
void menu();

int main() {
    Event schedules[20];
    int option;
    int cont = 0; // Contador para eventos cadastrados
    int i = 0; // Índice para a próxima posição no array

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerEvent(&schedules[i], &cont, &i);
                break;
            case 2:
                updateEvent(schedules, cont);
                break;
            case 3:
                search(schedules, cont);
                break;
            case 4:
                list(schedules, cont);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (option != 5);

    return 0;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Cadastrar Evento\n");
    printf("2. Atualizar Evento\n");
    printf("3. Pesquisar Evento\n");
    printf("4. Apresentar todos os Eventos\n");
    printf("5. Sair\n");
}

void registerEvent(Event *schedule, int *cont, int *i) {
    int r;
    schedule->title = malloc(sizeof(char) * 50);
    schedule->description = malloc(sizeof(char) * 1000);

    printf("\n\n\n[CADASTRO DE EVENTOS]\n\n\n");
    printf("Digite o nome do evento: \n");
    scanf(" %[^\n]", schedule->title);

    printf("Digite a descricao do evento: \n");
    scanf(" %[^\n]", schedule->description);

    printf("Digite a quantidade de ingressos para o evento: \n");
    scanf("%d", &schedule->ticketQuantity);

    schedule->ID = *cont + 1;

    printf("\n\n[EVENTO CADASTRADO COM SUCESSO!]\n\n");
    printf("- EVENTO: %s\n", schedule->title);
    printf("- ID do evento: %d\n", schedule->ID);
    printf("- DESCRICAO: %s\n", schedule->description);
    printf("- QUANTIDADE DE INGRESSOS: %d\n", schedule->ticketQuantity);

    printf("\n\nDeseja fazer alguma alteracao?\n");
    printf("SIM = 1\nNAO = 2\n");
    scanf("%d", &r);

    if (r == 1) {
        updateEvent(schedule, *cont);
    }

    (*cont)++;
    (*i)++;
}

void updateEvent(Event *schedules, int cont) {
    int r2, id;

    printf("\n\n[ATUALIZACAO DE EVENTO]\n\n");
    printf("Digite o ID do evento a ser atualizado:\n");
    scanf("%d", &id);

    for (int i = 0; i < cont; i++) {
        if (schedules[i].ID == id) {
            printf("Selecione a opcao que deseja atualizar\n");
            printf("\n1-Nome do evento\n2-Descricao do evento\n3-Numero de ingressos\n4-Todos\n");
            scanf("%d", &r2);

            switch (r2) {
                case 1:
                    printf("Digite o novo nome do evento:\n");
                    scanf(" %[^\n]", schedules[i].title);
                    break;
                case 2:
                    printf("Digite a nova descricao do evento:\n");
                    scanf(" %[^\n]", schedules[i].description);
                    break;
                case 3:
                    printf("Digite a nova quantidade de ingressos:\n");
                    scanf("%d", &schedules[i].ticketQuantity);
                    break;
                case 4:
                    printf("Digite o novo nome do evento:\n");
                    scanf(" %[^\n]", schedules[i].title);
                    printf("Digite a nova descricao do evento:\n");
                    scanf(" %[^\n]", schedules[i].description);
                    printf("Digite a nova quantidade de ingressos:\n");
                    scanf("%d", &schedules[i].ticketQuantity);
                    break;
                default:
                    break;
            }
            printf("[EVENTO ATUALIZADO COM SUCESSO!]\n\n");
            printf("- EVENTO: %s\n", schedules[i].title);
            printf("- DESCRICAO: %s\n", schedules[i].description);
            printf("- QUANTIDADE DE INGRESSOS: %d\n", schedules[i].ticketQuantity);
            return;
        }
    }

    printf("Evento com ID %d nao encontrado.\n", id);
}

void search(Event schedule[], int cont) {
    int id;
    printf("Digite o ID do evento a ser pesquisado: ");
    scanf("%d", &id);

    for (int i = 0; i < cont; i++) {
        if (schedule[i].ID == id) {
            printf("Registro encontrado:\n");
            printf("- EVENTO: %s\n", schedule[i].title);
            printf("- DESCRICAO: %s\n", schedule[i].description);
            printf("- QUANTIDADE DE INGRESSOS: %d\n", schedule[i].ticketQuantity);
            return;
        }
    }
    printf("Registro nao encontrado.\n");
}

void list(Event schedule[], int cont) {
    if (cont == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    printf("Apresentando todos os registros:\n");
    for (int i = 0; i < cont; i++) {
        printf("Registro %d:\n", i + 1);
        printf("- EVENTO: %s\n", schedule[i].title);
        printf("- DESCRICAO: %s\n", schedule[i].description);
        printf("- QUANTIDADE DE INGRESSOS: %d\n", schedule[i].ticketQuantity);
        printf("\n");
    }
}







