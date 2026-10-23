#include <stdio.h>
#include <limits.h>

void insert(int ary[], int hFn, int size) {
    int element, pos, n = 0;
    printf("Enter key element to insert\n");
    scanf("%d", &element);

    pos = element % hFn;

    while (ary[pos] != INT_MIN) {
        // INT_MIN and INT_MAX indicate that cell is empty or deleted
        if (ary[pos] == INT_MAX)
            break;

        pos = (pos + 1) % hFn;
        n++;

        if (n == size) {
            printf("Hash table is full. No place to insert this element.\n");
            return;
        }
    }

    ary[pos] = element; // Inserting element
}

void delete_element(int ary[], int hFn, int size) {
    int element, pos, n = 0;
    printf("Enter element to delete\n");
    scanf("%d", &element);

    pos = element % hFn;

    while (n++ != size) {
        if (ary[pos] == INT_MIN) {
            printf("Element not found in hash table\n");
            return;
        } else if (ary[pos] == element) {
            ary[pos] = INT_MAX; // Mark as deleted
            printf("Element deleted\n");
            return;
        }
        pos = (pos + 1) % hFn;
    }
    printf("Element not found in hash table\n");
}

void search(int ary[], int hFn, int size) {
    int element, pos, n = 0;
    printf("Enter element you want to search\n");
    scanf("%d", &element);

    pos = element % hFn;

    while (n++ != size) {
        if (ary[pos] == element) {
            printf("Element found at index %d\n", pos);
            return;
        } else if (ary[pos] == INT_MIN) {
            printf("Element not found in hash table\n");
            return;
        }
        pos = (pos + 1) % hFn;
    }
    printf("Element not found in hash table\n");
}

void display(int ary[], int size) {
    printf("Index\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", i);
        if (ary[i] == INT_MIN) {
            printf("Empty\n");
        } else if (ary[i] == INT_MAX) {
            printf("Deleted\n");
        } else {
            printf("%d\n", ary[i]);
        }
    }
}

int main() {
    int size, hFn, choice;

    printf("Enter size of hash table\n");
    scanf("%d", &size);

    int ary[size];

    printf("Enter hash function (if mod 10, enter 10)\n");
    scanf("%d", &hFn);

    for (int i = 0; i < size; i++)
        ary[i] = INT_MIN; // Assigning INT_MIN indicates that cell is empty

    do {
        printf("\nEnter your choice\n");
        printf("1 -> Insert\n2 -> Delete\n3 -> Display\n4 -> Search\n0 -> Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(ary, hFn, size);
                break;
            case 2:
                delete_element(ary, hFn, size);
                break;
            case 3:
                display(ary, size);
                break;
            case 4:
                search(ary, hFn, size);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter correct choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
