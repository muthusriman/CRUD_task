#include <stdio.h>
#include <stdlib.h>

#define max_size 100

void showMenu();
void createElement();
void readElement();
void updateElement();
void deleteElement();

int arr[max_size];
int size = 0;

int main() {
    while(1) {
        showMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createElement();
                break;
            case 2:
                readElement();
                break;
            case 3:
                updateElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void showMenu() {
    printf("\n\tMenu\n");
    printf("1. Create\n");
    printf("2. Read\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
}

void createElement() {
    if(size >= max_size) {
        printf("Element can't be added as array is full.\n");
        return;
    }
    printf("Enter the element to be added: ");
    scanf("%d", &arr[size]);
    size++;
    printf("Element added successfully.\n");
    readElement();
}

void readElement() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    } 

    printf("Element(s) in the array are: ");
    for(int i = 0; i < size; i++) { 
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void updateElement() {
    int index, new_value;
    
    if (size == 0) {
        printf("There's nothing to update as array is empty.\n");
        return;
    } 
    
    printf("Enter the index to be updated (0 to %d): ", size - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= size) {
        printf("Invalid index. Please try again.\n");
        return;
    } 
    
    printf("Enter the new element: ");
    scanf("%d", &new_value);
    arr[index] = new_value;
    printf("Element updated successfully.\n");
    readElement();
}

void deleteElement() {
    int index;
    
    if (size == 0) {
        printf("There's nothing to delete as array is empty.\n");
        return;
    } 
    
    printf("Enter the index to be deleted (0 to %d): ", size - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= size) {
        printf("Invalid index. Please try again.\n");
        return;
    } 
    
    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully.\n");
    readElement();
}