#ifndef AGENDA_UTILITARIOS_H

#include <stdbool.h>
#define AGENDA_UTILITARIOS_H

bool ler_Inteiro(long int *iLongo, const char *prompt, long int limite_inferior, long int limite_superior);
bool ler_String(char *buffer, const char *prompt, int tamanho);
#endif //AGENDA_UTILITARIOS_H