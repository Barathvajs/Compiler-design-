#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[50];
    int value;
    
} SymbolEntry;


SymbolEntry symbolTable[100]; 
int currentSize = 0;


void insertEntry(const char *name, int value) {
    if (currentSize < 100) { 
        SymbolEntry newEntry;
        strcpy(newEntry.name, name);
        newEntry.value = value;
        symbolTable[currentSize++] = newEntry;
        printf("Inserted: %s\n", name);
    } else {
        printf("Symbol table is full. Cannot insert %s\n", name);
    }
}


int searchEntry(const char *name) {
    for (int i = 0; i < currentSize; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Found: %s (Value: %d)\n", name, symbolTable[i].value);
            return i; 
        }
    }
    printf("Not found: %s\n", name);
    return -1; 
}

int main() {
    
    insertEntry("variable1", 10);
    insertEntry("variable2", 20);
    insertEntry("variable3", 30);

    searchEntry("variable2");
    searchEntry("variable4");

    return 0;
}

