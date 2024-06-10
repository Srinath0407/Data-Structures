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

void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    if (head == NULL || head->next == NULL) {
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next->prev = NULL;
    slow->next = NULL;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);

    printf("Original linked list: ");
    printList(head);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    splitList(head, &head1, &head2);

    printf("First half of the linked list: ");
    printList(head1);
    printf("Second half of the linked list: ");
    printList(head2);

    return 0;
}

