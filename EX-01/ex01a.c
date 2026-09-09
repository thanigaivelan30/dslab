#include <stdio.h>
#define MAX_SIZE 100

void createArray(int arr[], int *size) {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Error: Number of elements exceeds the maximum array size.\n");
        return;
    }
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    *size = n;
    printf("Array created successfully.\n");
}

// Added arr[] to the parameters so it can access the array
void insertElement(int arr[], int *size, int element, int position) {
    int i;
    if (*size >= MAX_SIZE) {
        printf("Error: Array is full. Cannot insert element.\n");
        return;
    }
    if ((position < 0) || (position > *size)) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

int searchElement(int arr[], int size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void deleteElement(int arr[], int *size, int position) {
    int i;
    if ((position < 0) || (position >= *size)) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

void displayArray(int arr[], int size) {
    int i;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, result;
    
    while (1) {
        printf("\nArray Operation Menu:\n");
        printf("1. Create Array\n");
        printf("2. Insert Element\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Display Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(arr, &size, element, position); // Now matches parameters
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                result = searchElement(arr, size, element);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else 
                    printf("Element not found\n");
                break;
            case 4:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 5:
                displayArray(arr, size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
