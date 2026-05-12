#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_LENGTH 100

/* Hash table */
char hashTable[TABLE_SIZE][MAX_LENGTH];

/* Initialize table */
void initialize() {

    int i;

    for (i = 0; i < TABLE_SIZE; i++) {

        strcpy(hashTable[i], "");
    }
}

/* Hash function */
int hashFunction(char str[]) {

    int sum = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {

        sum += str[i];
    }

    return sum % TABLE_SIZE;
}

/* Insert string using linear probing */
void insert(char str[]) {

    int index = hashFunction(str);
    int start = index;

    while (strcmp(hashTable[index], "") != 0) {

        index = (index + 1) % TABLE_SIZE;

        if (index == start) {

            printf("Hash Table Full.\n");
            return;
        }
    }

    strcpy(hashTable[index], str);

    printf("String inserted.\n");
}

/* Search string */
void search(char str[]) {

    int index = hashFunction(str);
    int start = index;

    while (strcmp(hashTable[index], "") != 0) {

        if (strcmp(hashTable[index], str) == 0) {

            printf("String found at index %d\n", index);

            return;
        }

        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            break;
        }
    }

    printf("String not found.\n");
}

/* Display hash table */
void display() {

    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < TABLE_SIZE; i++) {

        printf("%d -> %s\n", i, hashTable[i]);
    }
}

int main() {

    int choice;
    char str[MAX_LENGTH];

    initialize();

    while (1) {

        printf("\n===== Hashing Menu =====\n");

        printf("1. Insert String\n");
        printf("2. Search String\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter string to insert: ");
                scanf("%s", str);

                insert(str);

                break;

            case 2:

                printf("Enter string to search: ");
                scanf("%s", str);

                search(str);

                break;

            case 3:

                display();

                break;

            case 4:

                printf("Program terminated.\n");

                return 0;

            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}