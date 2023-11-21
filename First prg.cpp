#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10
#define MAX_FIRST 10

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_SYMBOLS][MAX_SYMBOLS];

char firstSets[MAX_RULES][MAX_FIRST];

int numRules;

bool isNonTerminal(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

void computeFirstSet(char symbol) {
    for (int i = 0; i < numRules; i++) {
        for (int j = 0; j < MAX_FIRST; j++) {
            firstSets[i][j] = '\0';
        }
    }

    bool changed = true;

    while (changed) {
        changed = false;

        for (int i = 0; i < numRules; i++) {
            int j = 0;
            while (productions[i][j][0] != '\0') {
                if (productions[i][j][0] == symbol) {
                    if (!isNonTerminal(productions[i][j][1])) {
                        int k;
                        for (k = 0; firstSets[i][k] != '\0'; k++) {
                            if (firstSets[i][k] == productions[i][j][1]) {
                                break;
                            }
                        }
                        if (firstSets[i][k] == '\0') {
                            firstSets[i][k] = productions[i][j][1];
                            firstSets[i][k + 1] = '\0';
                            changed = true;
                        }
                    } else {
                        int nonTerminalIndex;
                        for (nonTerminalIndex = 0; nonTerminals[nonTerminalIndex] != productions[i][j][1]; nonTerminalIndex++)
                            ;
                        for (int k = 0; firstSets[nonTerminalIndex][k] != '\0'; k++) {
                            int m;
                            for (m = 0; firstSets[i][m] != '\0'; m++) {
                                if (firstSets[i][m] == firstSets[nonTerminalIndex][k]) {
                                    break;
                                }
                            }
                            if (firstSets[i][m] == '\0') {
                                firstSets[i][m] = firstSets[nonTerminalIndex][k];
                                firstSets[i][m + 1] = '\0';
                                changed = true;
                            }
                        }
                    }
                }
                j++;
            }
        }
    }
}

int main() {
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

    char symbol;
    printf("Enter the non-terminal to compute FIRST set for: ");
    scanf(" %c", &symbol);

    computeFirstSet(symbol);

    printf("FIRST Sets for %c:\n", symbol);
    int index = symbol - 'A'; // Convert non-terminal to index
    for (int i = 0; firstSets[index][i] != '\0'; i++) {
        printf("%c ", firstSets[index][i]);
    }
    printf("\n");

    return 0;
}

