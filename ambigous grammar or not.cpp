#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

typedef struct {
    char symbol;
    char production[10];
} Rule;

Rule rules[MAX_RULES];
int numRules;

int isAmbiguous(char symbol) {
    int i, j;
    int count = 0;

    for (i = 0; i < numRules; i++) {
        if (rules[i].symbol == symbol) {
            for (j = i + 1; j < numRules; j++) {
                if (rules[j].symbol == symbol) {
                    if (strcmp(rules[i].production, rules[j].production) == 0) {
                        printf("Ambiguity found for symbol %c with production %s\n", symbol, rules[i].production);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of grammar rules: ");
    scanf("%d", &numRules);

    printf("Enter grammar rules (e.g., S aSa):\n");
    for (int i = 0; i < numRules; i++) {
        scanf(" %c %s", &rules[i].symbol, rules[i].production);
    }

    int ambiguous = 0;
    for (int i = 0; i < numRules; i++) {
        if (isAmbiguous(rules[i].symbol)) {
            ambiguous = 1;
        }
    }

    if (!ambiguous) {
        printf("The grammar is ambiguous.\n");
    }

    return 0;
}

