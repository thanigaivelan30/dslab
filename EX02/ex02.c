#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head_ref;
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    
    if (temp->data == key && temp->next == *head_ref) {
        *head_ref = NULL;
        free(temp);
        return;
    }

   
    if (temp->data == key) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = (*head_ref)->next;
        struct Node* toDelete = *head_ref;
        *head_ref = temp->next;
        free(toDelete);
    } else {
        
        while (temp->next != *head_ref && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data != key) {
            printf("Key not found in the list\n");
            return;
        }

        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int data, choice, key;

    do {
        printf("\n1. Insert at End");
        printf("\n2. Delete Node");
        printf("\n3. Print List");
        printf("\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                printf("Circular Linked List: ");
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    
    if (head != NULL) {
        struct Node* current = head;
        struct Node* temp;
        do {
            temp = current;
            current = current->next;
            free(temp);
        } while (current != head);
    }

    return 0;
}
