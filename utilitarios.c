
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "utilitarios.h"

bool ler_Inteiro(long int *iLongo,
                 const char *prompt,
                 long int limite_inferior,
                 long int limite_superior)
{
    char buffer[4096];
    char *p;

    do
    {
        if (prompt != NULL)
            printf("%s (%ld a %ld): ", prompt, limite_inferior, limite_superior);

        memset(buffer, 0, 4096);
        fgets(buffer, 4096, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        p = NULL;
        errno = 0;
        *iLongo = strtol(buffer, &p, 10);
        if ((p == buffer) || (errno == ERANGE) || (*p && *p != '\n'))
            return false;
        if ((*iLongo >= limite_inferior) && (*iLongo <= limite_superior))
            break;
    } while (1);

    return true;
}

bool ler_String(char *buffer, const char *prompt, int tamanho)
{
    if (prompt != NULL)
        printf("%s (ate %d caracteres): ", prompt, tamanho);

    memset(buffer, 0, tamanho);
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    return true;
}


