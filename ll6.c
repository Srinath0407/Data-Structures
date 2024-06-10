#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void removeNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;

    struct Node* current = *head_ref;
    while (current != NULL && current->data != key)
        current = current->next;

    if (current == NULL)
        return;

    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    if (*head_ref == current)
        *head_ref = current->next;

    free(current);
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);

    printf("Original linked list: ");
    printList(head);

    int key = 10;
    removeNode(&head, key);

    printf("Linked list after removing %d: ", key);
    printList(head);

    return 0;
}

