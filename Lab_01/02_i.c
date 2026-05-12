#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    char result[MAX_LENGTH] = "";
    char temp[MAX_LENGTH];

    int i = 0, j = 0;
    int wordPosition = 1;

    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    while (sentence[i] != '\0') {

        j = 0;

        while (sentence[i] != ' ' && sentence[i] != '\0') {
            temp[j++] = sentence[i++];
        }

        temp[j] = '\0';

        /* Reverse word if:
           - word length is odd
           - word is at even position
        */
        if ((wordPosition % 2 == 0) && (strlen(temp) % 2 != 0)) {
            reverseWord(temp);
        }

        strcat(result, temp);

        if (sentence[i] == ' ') {
            strcat(result, " ");
            i++;
        }

        wordPosition++;
    }

    printf("\nModified sentence:\n%s\n", result);

    return 0;
}