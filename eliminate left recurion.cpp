#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_SYMBOLS][MAX_SYMBOLS];

void eliminateLeftRecursion(int numRules) {
    for (int i = 0; i < numRules; i++) {
        for (int j = 0; j < i; j++) {
            char currentNonTerminal = nonTerminals[i];
            char newNonTerminal = nonTerminals[i] + '\'';

            if (productions[i][0][0] == nonTerminals[i]) {
                int index = 0;

                while (productions[i][index][0] != '\0') {
                    index++;
                }

                for (int k = 0; k < index; k++) {
                    if (productions[i][k][0] != nonTerminals[i]) {
                        int len = strlen(productions[i][k]);
                        for (int l = 0; l <= len; l++) {
                            productions[numRules][k][l] = productions[i][k][l];
                        }
                    }
                }

                productions[numRules][index][0] = newNonTerminal;
                productions[numRules][index][1] = '\0';

                for (int k = 0; k < index; k++) {
                    if (productions[i][k][0] != '\0' && productions[i][k][0] != nonTerminals[i]) {
                        int len = strlen(productions[numRules][k]);
                        for (int l = 0; l <= len; l++) {
                            productions[i][k][l] = productions[numRules][k][l];
                        }
                    } else {
                        break;
                    }
                }

                productions[numRules + 1][0][0] = 'e';
                productions[numRules + 1][0][1] = '\0';

                numRules += 2;
            }
        }
    }
}

int main() {
    int numRules;

    printf("Enter the number of production rules: ");
    scanf("%d", &numRules);

    printf("Enter the non-terminals and production rules:\n");
    for (int i = 0; i < numRules; i++) {
        scanf(" %c", &nonTerminals[i]);
        scanf("%s", productions[i][0]);
        char delimiter;
        int j = 1;
        while (scanf("%c", &delimiter) == 1 && delimiter == '|') {
            scanf("%s", productions[i][j++]);
        }
        productions[i][j][0] = '\0';
    }

    eliminateLeftRecursion(numRules);

    printf("The grammar after left recursion elimination:\n");
    for (int i = 0; i < numRules; i++) {
        printf("%c -> %s", nonTerminals[i], productions[i][0]);
        for (int j = 1; productions[i][j][0] != '\0'; j++) {
            printf(" | %s", productions[i][j]);
        }
        printf("\n");
    }

    return 0;
}
