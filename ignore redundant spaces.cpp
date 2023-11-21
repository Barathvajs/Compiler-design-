#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void removeRedundantSpaces(char *line) {
    int inputLength = strlen(line);
    int currentIndex = 0;
    bool inComment = false;
    char modifiedLine[inputLength + 1];

    for (int i = 0; i < inputLength; i++) {
        if (inComment) {
            
            if (line[i] == '*' && line[i + 1] == '/') {
                inComment = false;
                i++;
            }
        } else {
            if (line[i] == '/' && line[i + 1] == '*') {
                
                inComment = true;
                i++;
            } else if (line[i] == '/' && line[i + 1] == '/') {
                
                break;
            } else if (line[i] == ' ' || line[i] == '\t') {
                
                modifiedLine[currentIndex++] = ' ';
                while (line[i] == ' ' || line[i] == '\t') {
                    i++;
                }
                i--;
            } else {
                modifiedLine[currentIndex++] = line[i];
            }
        }
    }

    modifiedLine[currentIndex] = '\0';
    strcpy(line, modifiedLine);
}

int main() {
    char input[1000]; 

    printf("Enter C code (use Ctrl+D to end input):\n");


    while (fgets(input, sizeof(input), stdin) != NULL) {
        removeRedundantSpaces(input);
        printf("%s", input);
    }

    return 0;
}

