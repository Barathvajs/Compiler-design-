#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeComments(char* code) {
    bool inCommentBlock = false;

    for (int i = 0; code[i] != '\0'; i++) {
        if (!inCommentBlock && code[i] == '/' && code[i + 1] == '/') {
            while (code[i] != '\n' && code[i] != '\0') {
                code[i] = ' ';
                i++;
            }
        }
        else if (!inCommentBlock && code[i] == '/' && code[i + 1] == '*') {
            inCommentBlock = true;
            code[i] = ' ';
            code[i + 1] = ' ';
            i += 2;
        }
        else if (inCommentBlock && code[i] == '*' && code[i + 1] == '/') {
            inCommentBlock = false;
            code[i] = ' ';
            code[i + 1] = ' ';
            i += 2;
        }
        if (inCommentBlock) {
            code[i] = ' ';
        }
    }
}

int main() {
    char input[1000];
    printf("Enter code (end with Ctrl+D on Unix or Ctrl+Z on Windows):\n");

    char ch;
    int index = 0;
    while ((ch = getchar()) != EOF) {
        input[index] = ch;
        index++;
    }
    input[index] = '\0';

    removeComments(input);

    int i, j;
    bool spaceBefore = true;

    for (i = j = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && input[i] != '\t') {
            if (!spaceBefore && input[i] == '\n') {
                
                continue;
            }
            spaceBefore = false;
            input[j] = input[i];
            j++;
        } else {
            spaceBefore = true;
        }
    }
    input[j] = '\0';

    printf("Code after removing comments and redundant spaces/tabs:\n");
    printf("%s\n", input);

    return 0;
}
