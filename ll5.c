#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

void update(struct Node* head, int old_data, int new_data) {
    struct Node* node = search(head, old_data);
    if (node != NULL)
        node->data = new_data;
    else
        printf("Element %d not found in the list.\n", old_data);
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    printf("Original linked list: ");
    printList(head);

    int old_data = 10;
    int new_data = 20;
    update(head, old_data, new_data);

    printf("Updated linked list: ");
    printList(head);

    return 0;
}

