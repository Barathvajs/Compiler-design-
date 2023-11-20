#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isValidIdentifier(const char *str) 
{
    if (strlen(str) == 0 || isdigit(str[0]))
        return false;

    for (int i = 0; str[i] != '\0'; i++) 
	{
        if (!(isalnum(str[i]) || str[i] == '_')) 
		{
            return false;
        }
    }

    return true; 
}
int main() 
{
    char identifier[100];
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) 
	{
        printf("'%s' is a valid identifier in C.\n", identifier);
    } else 
	{
        printf("'%s' is NOT a valid identifier in C.\n", identifier);
    }

    return 0;
}
