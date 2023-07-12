#include "pista.h"
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

// Outras funções necessárias

void copia(char *copia, char *origem) {
  int i;
  for (i = 0; origem[i] != '\0'; i++) {
    copia[i] = origem[i];
  }
  copia[i] = '\0';
}

Fila *Inicializa() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  return fila;
}

void Esvaziar(Fila *fila) {
  fila->frente = (Apontador)malloc(sizeof(Celula));
  fila->tras = fila->frente;
  fila->frente->prox = NULL;
}

int Vazia(Fila *fila) { return (fila->frente == fila->tras); }

Aviao Inicializa_aviao(char *nome, int identificador) {
  Aviao temporario;
  copia(temporario.nome, nome);
  temporario.identificador = identificador;
  return temporario;
}

// c. Adicionar um avião à fila de espera
void adiciona_espera(Aviao x, Fila *fila) {
  fila->tras->prox = (Apontador)malloc(sizeof(Celula));
  fila->tras = fila->tras->prox;
  fila->tras->info = x;
  fila->tras->prox = NULL;
}

// b. Autorizar a decolagem do primeiro avião (desenfileirar)
Aviao decolagem(Fila *fila) {

  Apontador q;

  q = fila->frente;

  fila->frente = fila->frente->prox;
  free(q);

  return fila->frente->info;
}

// a. Listar o número de aviões aguardando numa fila de decolagem (tamanho)
int numero_fila(Fila *fila) {
  Apontador E = (Apontador)malloc(sizeof(Apontador));
  int contador = 0;

  for (E = fila->frente->prox; E != NULL; E = E->prox) {
    contador++;
  }

  return contador;
}

// d. Listar todos os aviões na fila de espera (imprimir)
void fila_espera(Fila *fila) {
  if (Vazia(fila))
    cout << "A fila esta sem avioes para decolagem !!!" << endl;
  else {
    Apontador E = (Apontador)malloc(sizeof(Apontador));
    int i = 1;

    for (E = fila->frente->prox; E != NULL; E = E->prox) {
      cout << "Aviao " << i << ":" << endl;
      cout << "Nome: " << E->info.nome << endl;
      cout << "Identificador: " << E->info.identificador << endl;
      i++;
      cout << "-------------------------------------------------" << endl;
    }
  }
}

// e. Listar as caracteristicas do primeiro aviao (buscar primeiro elemento)
void primeiro_aviao(Fila *fila) {
  if (Vazia(fila))
    cout << "A fila nao possui avioes !!!" << endl;
  else {
    Apontador E = (Apontador)malloc(sizeof(Apontador));
    E = fila->frente->prox;

    cout << "Aviao: " << E->info.nome << endl;
    cout << "Identificador: " << E->info.identificador << endl;
  }
}
