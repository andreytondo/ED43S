/*
Escreva uma função que recebe duas listas encadeadas e concatena as duas
(liga a segunda lista no final da primeira lista)
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

void concatenateLists(Node **head1, Node **head2) {
    Node *current = *head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *head2;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;

    insertNode(&head1, 1);
    insertNode(&head1, 2);
    insertNode(&head1, 3);
    insertNode(&head1, 4);
    insertNode(&head1, 5);

    insertNode(&head2, 6);
    insertNode(&head2, 7);
    insertNode(&head2, 8);
    insertNode(&head2, 9);
    insertNode(&head2, 10);

    printf("Lista 1: ");
    printList(head1);
    printf("Lista 2: ");
    printList(head2);

    concatenateLists(&head1, &head2);
    printf("Lista concatenada: ");
    printList(head1);

    return 0;
}