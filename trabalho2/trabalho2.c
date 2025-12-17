#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

EstruturaAuxiliar *vetorPrincipal[TAM];

void inicializar () {
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i] = NULL;
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice] != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    
    else if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
        
    else if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }
    
    EstruturaAuxiliar *novaEstrutura = (EstruturaAuxiliar*) malloc (sizeof (EstruturaAuxiliar));
    
    if (novaEstrutura == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    novaEstrutura->elementos = (int *) malloc (tamanho * sizeof (int));
    
    if (novaEstrutura->elementos == NULL) {
        free (novaEstrutura);
        return SEM_ESPACO_DE_MEMORIA;
    }
   
    novaEstrutura->tamanho_maximo = tamanho;
    novaEstrutura->qtd_elementos = 0;
    vetorPrincipal[indice] = novaEstrutura;

    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int indice = posicao - 1;
    

    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
    else
    {
        if (vetorPrincipal[indice] != NULL)
        {
            if (vetorPrincipal[indice]->qtd_elementos < vetorPrincipal[indice]->tamanho_maximo)
            {
                vetorPrincipal[indice]->elementos[vetorPrincipal[indice]->qtd_elementos] = valor;
                vetorPrincipal[indice]->qtd_elementos++;

                return SUCESSO;
            }
            else
            {
                return SEM_ESPACO;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = 0;
    int indice = posicao - 1;
    
    if (posicao < 1 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;    
    }
    
    else if (vetorPrincipal[indice] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    else if (vetorPrincipal[indice]->qtd_elementos == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    else {
        
        vetorPrincipal[indice]->qtd_elementos--;
        retorno = SUCESSO;
        
    }
    
    return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int indice = posicao - 1;
    
    if (posicao < 1 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[indice] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[indice]->qtd_elementos == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    else {
        for (int i = 0; i < vetorPrincipal[indice]->qtd_elementos; i++) {
            if (valor == vetorPrincipal[indice]->elementos[i]) {
                for (int j = i; j < vetorPrincipal[indice]->qtd_elementos-1; j++) {
                    vetorPrincipal[indice]->elementos[j] = vetorPrincipal[indice]->elementos[j+1];
                }
                vetorPrincipal[indice]->qtd_elementos--;
                return SUCESSO;
            }
        }
        if (!retorno) {
            return NUMERO_INEXISTENTE;
        }
    }
    
    return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int indice = posicao - 1;

    if (posicao < 1 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
    }

    else if (vetorPrincipal[indice] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    else {
        for (int i = 0; i < vetorPrincipal[indice]->qtd_elementos; i++) {
            vetorAux[i] = vetorPrincipal[indice]->elementos[i];
        }
        retorno = SUCESSO;
    }
    
    return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int indice = posicao - 1;
    int temp;

    if (posicao < 1 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
    }

    else if (vetorPrincipal[indice] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    else {
        for (int i = 0; i < vetorPrincipal[indice]->qtd_elementos; i++) {
            vetorAux[i] = vetorPrincipal[indice]->elementos[i];
        }
        
        for (int i = 0; i < vetorPrincipal[indice]->qtd_elementos; i++) {
            for (int j = i+1; j < vetorPrincipal[indice]->qtd_elementos; j++) {
                if (vetorAux[i] > vetorAux[j]) {
                    temp = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = temp;
                }
            }
        }
        retorno = SUCESSO;
    }

    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int i, j, k = 0;
    
    int teste = 0;
    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->qtd_elementos > 0) 
            teste = 1;
    }
    if (teste == 0) {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    else {
        for (i = 0; i < TAM; i++) {
            if (vetorPrincipal[i] != NULL) {
                for (j = 0; j < vetorPrincipal[i]->qtd_elementos; j++) {
                    vetorAux[k] = vetorPrincipal[i]->elementos[j];
                    k++;
                }
            }
        }
        retorno = SUCESSO;
    }
    
    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i, j, temp;
    int retorno = getDadosDeTodasEstruturasAuxiliares (vetorAux);
    
    if (retorno == SUCESSO) {
        int total_elementos = 0;
        for (i = 0; i < TAM; i++) {
            if (vetorPrincipal[i] != NULL)
                total_elementos += vetorPrincipal[i]->qtd_elementos;
        }
        
        for (i = 0; i < total_elementos; i++) {
            for (j = i+1; j < total_elementos; j++) {
                if (vetorAux[i] > vetorAux[j]) {
                    temp = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = temp;
                }
            }
        }
    }
    
    return retorno;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    int indice = posicao - 1;

    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
    
    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int tamanhoFinal = vetorPrincipal[indice]->tamanho_maximo + novoTamanho;
    
    if (tamanhoFinal < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }
    
    int *temp = (int *) realloc (vetorPrincipal[indice]->elementos, tamanhoFinal * sizeof (int));
    
    if (temp == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    vetorPrincipal[indice]->elementos = temp;
    vetorPrincipal[indice]->tamanho_maximo = tamanhoFinal;
    
    if (vetorPrincipal[indice]->qtd_elementos > tamanhoFinal) {
        vetorPrincipal[indice]->qtd_elementos = tamanhoFinal;
    }
    
    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;
    int indice = posicao - 1;
    
     if (posicao < 1 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[indice] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
   
    else {
        retorno = vetorPrincipal[indice]->qtd_elementos;
    }
    
    return retorno;
}

No *montarListaEncadeadaComCabecote()
{
    int temDados = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
        temDados++;
        break;
        }
    }
    if (!temDados) return NULL;
    
    
    No *inicio = (No *) malloc (sizeof (No));
    if (inicio == NULL) return NULL;
    
    inicio->prox = NULL;
    No *atual = inicio; 
    
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            for (int j = 0; j < vetorPrincipal[i]->qtd_elementos; j++) {
                No *novo = (No *) malloc (sizeof (No));
                novo->conteudo = vetorPrincipal[i]->elementos[j];
                novo->prox = NULL;
                atual->prox = novo;
                atual = novo;
            }
        }
    }

    return inicio;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio->prox;
    
    for (int i = 0; atual != NULL; i++) {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    No *proximo;
    
    while (atual != NULL) {
        proximo = atual->prox;
        free (atual);
        atual = proximo;
    }
    *inicio = NULL;
}

void finalizar()
{
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free (vetorPrincipal[i]->elementos);
            free (vetorPrincipal[i]);
        }
    }
}
