

#ifndef AGENDA_LISTA_H
#define AGENDA_LISTA_H
typedef enum
{
    ERRO_SUCESSO,
    ERRO_POSICAO_INVALIDA,
    ERRO_LISTA_CHEIA,
    ERRO_LISTA_VAZIA,
    ERRO_CHAVE_INEXISTENTE
} ERRO_LISTA;

typedef enum
{
    NOME,
    TELEFONE,
    EMAIL
} CRITERIO;

typedef struct st_registro
{
    char nome[35];
    char email[40];
    unsigned int ddd;
    char telefone[10];
} REGISTRO;

typedef struct st_nodo
{
    REGISTRO dado;
    struct st_nodo *proximo;
} NODO;

typedef struct st_descritor {
    unsigned int num_elementos;
    NODO *inicio;
    NODO *final;
} LISTA;

ERRO_LISTA agenda_inicializar(LISTA* lista);
ERRO_LISTA agenda_destruir (LISTA *lista);

unsigned int agenda_tamanho(const LISTA* lista);

ERRO_LISTA agenda_inserir(LISTA *lista, REGISTRO dado);
ERRO_LISTA agenda_remover(LISTA *lista, char *email);
ERRO_LISTA agenda_alterar_contato(LISTA *lista, REGISTRO *registro);
ERRO_LISTA agenda_buscar(const LISTA *lista, REGISTRO *registro, CRITERIO opcao);
void mostra_contato (const REGISTRO* dado);
void agenda_mostrar(const LISTA *lista);
#endif //AGENDA_LISTA_H