/*
Escreva uma função que recebe duas listas. A primeira guarda n números
inteiros e a segunda está vazia. A função deve inserir os elementos da primeira
lista na segunda lista, de maneira ordenada.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertOrdered(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL && current->data < data) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        previous->next = newNode;
        newNode->next = current;
    }
}

void insertListOrdered(Node **head1, Node **head2) {
    Node *current = *head1;
    while (current != NULL) {
        insertOrdered(head2, current->data);
        current = current->next;
    }
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;

    insertNode(&head1, 5);
    insertNode(&head1, 4);
    insertNode(&head1, 3);
    insertNode(&head1, 2);
    insertNode(&head1, 1);

    printf("Lista 1: ");
    printList(head1);
    printf("Lista 2: ");
    printList(head2);

    insertListOrdered(&head1, &head2);

    printf("Lista 1: ");
    printList(head1);
    printf("Lista 2: ");
    printList(head2);

    return 0;
}