// Grupo:
// Thiago Araujo Franco
// Hector Decarli Cardoso
// Gustavo Majid
#include <stdio.h>
#include "utilitarios.h"
#include "lista.h"

unsigned short int menu();
int main()
{
    unsigned short int opcao;
    LISTA agenda;

    agenda_inicializar(&agenda);
    REGISTRO dado;
    long ddd;

    do
    {
        opcao = menu();
        switch (opcao)
        {
            case 1:
                ler_String(dado.nome, "Informe o nome do contato", 35);
                ler_String(dado.email, "Informe o email do contato", 40);
                while (!ler_Inteiro(&ddd, "Informe o DDD do contato", 11, 97));
                dado.ddd = ddd;
                ler_String(dado.telefone, "Informe o telefone", 10);

                if (agenda_inserir(&agenda, dado) != ERRO_SUCESSO)
                {
                    printf("Erro na adicao do contato\n");
                }
                break;
            case 2:
                ler_String(dado.nome, "Informe o nome do contato", 35);
                if (agenda_buscar(&agenda, &dado, NOME) == ERRO_CHAVE_INEXISTENTE)
                {
                    printf("Nao temos esse contato na agenda\n");
                    continue;
                }
                mostra_contato(&dado);
                break;
            case 3:
                while (!ler_Inteiro(&ddd, "Informe o DDD do contato", 11, 97));
                ler_String(dado.telefone, "Informe o telefone do contato", 10);
                if (agenda_buscar(&agenda, &dado, TELEFONE) == ERRO_CHAVE_INEXISTENTE)
                {
                    printf("Nao temos esse contato na agenda\n");
                    continue;
                }
                mostra_contato(&dado);
                break;
            case 4:
                ler_String(&dado.email, "Informe o email do contato", 40);
                if (agenda_buscar(&agenda, &dado, EMAIL) == ERRO_CHAVE_INEXISTENTE)
                {
                    printf("Nao temos esse contato na agenda\n");
                    continue;
                }
                mostra_contato(&dado);
                break;
            case 5:
                ler_String(&dado.email, "Informe o email do contato", 40);
                if (agenda_remover(&agenda, &dado.email) == ERRO_CHAVE_INEXISTENTE) {
                        printf("Nao temos esse contato na agenda\n");
                        continue;
                    }
                agenda_mostrar(&agenda);
                break;
            case 6:
                ler_String(&dado.email, "Informe o email do contato", 40);
                if (agenda_alterar_contato(&agenda, &dado.email) == ERRO_CHAVE_INEXISTENTE)
                {
                    printf("Nao temos esse contato na agenda\n");
                    continue;
                }
                break;
            case 7:
                agenda_mostrar(&agenda);
                break;
            case 0:
                printf("Tchau!\n");
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}


unsigned short int menu()
{
    long opcao;
    printf("===============[ Menu ]===============\n");
    putchar('\n');
    printf("  [1] Adicionar contato\n");
    printf("  [2] Buscar por nome\n");
    printf("  [3] Buscar por DDD + telefone\n");
    printf("  [4] Buscar por email\n");
    printf("  [5] Remover contato por email\n");
    printf("  [6] Alterar dados do contato\n");
    printf("  [7] Mostrar a agenda\n");
    printf("  [0] Finalizar\n");
    putchar('\n');
    while(!ler_Inteiro(&opcao, "Digite a opcao desejada", 0, 7));
    return (unsigned short int) opcao;
}