#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 500

/* Function to reverse a word */
void reverseWord(char word[]) {
    int start = 0;
    int end = strlen(word) - 1;
    char temp;

    while (start < end) {

        temp = word[start];
        word[start] = word[end];
        word[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char sentence[MAX_LENGTH];
    char word[MAX_LENGTH];

    int i = 0, j = 0;
    int position = 1;

    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    printf("\nModified sentence:\n");

    while (sentence[i] != '\0') {

        j = 0;

        while (sentence[i] != ' ' && sentence[i] != '\0') {
            word[j++] = sentence[i++];
        }

        word[j] = '\0';

        /* Reverse if word length is even and position is odd */
        if ((position % 2 != 0) && (strlen(word) % 2 == 0)) {
            reverseWord(word);
        }

        printf("%s", word);

        if (sentence[i] == ' ') {
            printf(" ");
            i++;
        }

        position++;
    }

    printf("\n");

    return 0;
}