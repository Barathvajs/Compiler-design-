#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10
#define MAX_FOLLOW 10

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_SYMBOLS][MAX_SYMBOLS];

char followSets[MAX_RULES][MAX_FOLLOW];

int numRules;

bool isNonTerminal(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

void computeFollowSet(char symbol) {
    // Function to compute FOLLOW set for the given symbol
    // (Your implementation remains unchanged)
    // ...
    // (Your existing code for computing FOLLOW sets)
    // ...
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
    printf("Enter the non-terminal to compute FOLLOW set for: ");
    scanf(" %c", &symbol);

    computeFollowSet(symbol);

    // Print the FOLLOW set for the given non-terminal symbol
    printf("FOLLOW Sets for %c:\n", symbol);
    int index = symbol - 'A'; // Convert non-terminal to index
    for (int i = 0; followSets[index][i] != '\0'; i++) {
        printf("%c ", followSets[index][i]);
    }
    printf("\n");

    return 0;
}

