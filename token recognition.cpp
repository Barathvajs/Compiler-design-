#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool isKeyword(const char *word) {
    
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }

    return false;
}


bool isConstant(const char *word) {
    int i = 0;

   
    if (word[i] == '-' || word[i] == '+') {
        i++;
    }

    bool hasDot = false;

    
    while (word[i] != '\0') {
        if (isdigit(word[i])) {
            i++;
        } else if (word[i] == '.' && !hasDot) {
            hasDot = true;
            i++;
        } else {
            return false;
        }
    }

    return true;
}


bool isOperator(const char *word) {
    
    const char *operators[] = {
        "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=",
        "&&", "||", "&", "|", "!", "&=", "|=", "<<", ">>", "++", "--"
    };

    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (strcmp(word, operators[i]) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    char code[1000];  

    printf("Enter C code: ");
    fgets(code, sizeof(code), stdin);

    char *token = strtok(code, " \t\n\r,;(){}"); 

    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isConstant(token)) {
            printf("Constant: %s\n", token);
        } else if (isOperator(token)) {
            printf("Operator: %s\n", token);
        } else {
            printf("Identifier: %s\n", token);
        }

        token = strtok(NULL, " \t\n\r,;(){}");
    }

    return 0;
}
