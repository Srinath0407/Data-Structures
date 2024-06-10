#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void combineLists(struct Node** head1_ref, struct Node* head2) {
    if (*head1_ref == NULL) {
        *head1_ref = head2;
        return;
    }

    struct Node* current = *head1_ref;
    while (current->next != NULL)
        current = current->next;

    current->next = head2;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insertAtEnd(&head1, 5);
    insertAtEnd(&head1, 10);
    insertAtEnd(&head1, 15);

    insertAtEnd(&head2, 20);
    insertAtEnd(&head2, 25);
    insertAtEnd(&head2, 30);

    printf("Original linked list 1: ");
    printList(head1);
    printf("Original linked list 2: ");
    printList(head2);

    combineLists(&head1, head2);

    printf("Combined linked list: ");
    printList(head1);

    return 0;
}

