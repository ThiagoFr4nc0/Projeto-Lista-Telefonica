//
// Created by danie on 01/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "utilitarios.h"
#include <string.h>
#include "lista.h"

ERRO_LISTA agenda_inicializar(LISTA* lista)
{
    lista->num_elementos = 0;
    lista->inicio = NULL;
    lista->final = NULL;

    return ERRO_SUCESSO;
}

ERRO_LISTA agenda_destruir (LISTA *lista)
{
    NODO *prox, *aux;

    aux = lista->inicio;
    while (aux != NULL)
    {
        prox = aux->proximo;
        free(aux);
        aux = prox;
    }
    lista->num_elementos = 0;
    lista->inicio = NULL;
    lista->final = NULL;
    return ERRO_SUCESSO;
}

unsigned int agenda_tamanho(const LISTA* lista)
{
    return lista->num_elementos;
}

ERRO_LISTA agenda_inserir(LISTA *lista, REGISTRO dado)
{
    NODO *aux, *ant, *novo;

    // antes, procurar na agenda por um registro com o mesmo email
    // se encontar, retornar erro de chave duplicada

    novo = (NODO *) malloc(sizeof (NODO));
    if (novo == NULL)
    {
        return ERRO_LISTA_CHEIA;
    }

    novo->dado = dado;
    ant = NULL;
    aux = lista->inicio;
    while ((aux != NULL) && (strncmp(aux->dado.nome, dado.nome, strlen(aux->dado.nome)) < 0))
    {
        ant = aux;
        aux = aux->proximo;
    }

    if (aux == NULL) // nao achou e chegou ao final da lista
    {
        lista->final = novo;
    }
    novo->proximo = aux;
    if (ant == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        ant->proximo = novo;
    }
    lista->num_elementos = lista->num_elementos + 1;
    return ERRO_SUCESSO;
}

ERRO_LISTA agenda_remover(LISTA *lista, REGISTRO *registro)
{
        NODO *prox,*temp,*aux;

        aux = lista->inicio;
        temp = lista->inicio;

        while ((aux != NULL) && (strncmp(registro->email, aux->dado.email, strlen(registro->email)) != 0))
        {
            temp = aux;
            aux = aux->proximo;
        }

        if (aux == NULL) // chegou no final da lista
        {
            return ERRO_CHAVE_INEXISTENTE;
        }
        prox = aux->proximo;
        temp->proximo = prox;
        free(aux);

        return ERRO_SUCESSO;
}

ERRO_LISTA agenda_alterar_contato(LISTA *lista, REGISTRO *registro)
{
    NODO *aux;

    aux = lista->inicio;

    while ((aux != NULL) && (strncmp(registro->email, aux->dado.email, strlen(registro->email)) != 0))
    {
        aux = aux->proximo;
    }

    if (aux == NULL) // chegou no final da lista
    {
        return ERRO_CHAVE_INEXISTENTE;
    }
    *registro = aux->dado;
    ler_String(aux->dado.nome, "Informe o nome do contato", 35);
    ler_String(aux->dado.email, "Informe o email do contato", 40);
    ler_Inteiro(aux->dado.ddd, "Informe o DDD do contato", 11, 97);
    ler_String(aux->dado.telefone, "Informe o telefone", 10);
    *registro = aux->dado;


    return ERRO_SUCESSO;
}

ERRO_LISTA agenda_buscar(const LISTA *lista, REGISTRO *registro, CRITERIO opcao)
{
    NODO *aux;

    aux = lista->inicio;
    switch (opcao)
    {
        case NOME:
            while ((aux != NULL) && (strncmp(registro->nome, aux->dado.nome, strlen(registro->nome)) != 0))
            {
                aux = aux->proximo;
            }
            break;
        case TELEFONE:
            while ((aux != NULL) && (strncmp(registro->telefone, aux->dado.telefone, strlen(registro->telefone)) != 0))
            {
                aux = aux->proximo;
            }
            break;
        case EMAIL:
            while ((aux != NULL) && (strncmp(registro->email, aux->dado.email, strlen(registro->email)) != 0))
            {
                aux = aux->proximo;
            }
            break;
    }
    if (aux == NULL) // chegou no final da lista
    {
        return ERRO_CHAVE_INEXISTENTE;
    }

    *registro = aux->dado;

    return ERRO_SUCESSO;
}
void agenda_mostrar(const LISTA *lista)
{
    NODO *aux;
    printf("===============[ Meus contatos ]===============\n");
    printf("%-35s %-40s %3s %-10s\n", "Nome", "email", "DDD", "Telefone");
    aux = lista->inicio;
    while(aux != NULL)
    {
        printf("%-35s %-40s %3u %-10s\n", aux->dado.nome, aux->dado.email, aux->dado.ddd, aux->dado.telefone);
        aux = aux->proximo;
    }
    printf("===============================================\n");
}


void mostra_contato (const REGISTRO* dado)
{
    printf("Nome.....: %s\n", dado->nome);
    printf("email....: %s\n", dado->email);
    printf("Telefone.: (%2u) %s\n", dado->ddd, dado->telefone);
}

