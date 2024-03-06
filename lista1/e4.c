/*
Utilize uma estrutura TAD de lista encadeada para representar um sistema para
controlar a agenda telefônica de uma pessoa. (Peso 4,0)
    a) Considere que a struct a ser criada para armazenar os dados deve ser
    nomeada com o SEUNOME e deve ter campos referentes ao nome do
    contato, telefone e e-mail.

    b) Crie um programa que simula a criação, inclusão, exclusão e impressão dos
    dados sugeridos, sendo cadastrados pelo menos quatro registros de
    contatos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    struct Contact *next;
} Contact;

Contact *createContact(char name[], char phone[], char email[]) {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    newContact->next = NULL;
    return newContact;
}

void insertContact(Contact **head, char name[], char phone[], char email[]) {
    Contact *newContact = createContact(name, phone, email);
    newContact->next = *head;
    *head = newContact;
}

void printContact(Contact *head) {
    Contact *current = head;
    while (current != NULL) {
        printf("Nome: %s\n", current->name);
        printf("Telefone: %s\n", current->phone);
        printf("E-mail: %s\n", current->email);
        printf("\n");
        current = current->next;
    }
}

void deleteContact(Contact **head, char name[]) {
    Contact *current = *head;
    Contact *previous = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Contato não encontrado\n");
    } else if (previous == NULL) {
        *head = current->next;
        free(current);
    } else {
        previous->next = current->next;
        free(current);
    }
}

int main() {
    Contact *head = NULL;

    insertContact(&head, "João", "1234-5678", "teste1@mail.com");
    insertContact(&head, "Maria", "8765-4321", "teste2@mail.com");
    insertContact(&head, "José", "4321-5678", "teste3@mail.com");
    insertContact(&head, "Ana", "5678-4321", "teste4@mail.com");

    printf("====================== Agenda: ======================\n");
    printContact(head);
    deleteContact(&head, "Maria");

    printf("=============== Agenda após exclusão: ===============\n");
    printContact(head);
    
    return 0;
}
    