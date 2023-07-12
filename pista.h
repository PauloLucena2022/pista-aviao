#include <iostream>

using namespace std;

typedef struct{
  char nome[40];
  int identificador;
}Aviao;

typedef struct celula_str *Apontador;

typedef struct celula_str{
  Aviao info;
  Apontador prox;
}Celula;

typedef struct{
  Aviao info; 
  Apontador frente, tras;
}Fila;

// a. Listar o número de aviões aguardando numa fila de decolagem (tamanho)
int numero_fila(Fila*);

// b. Autorizar a decolagem do primeiro avião (desenfileirar)
Aviao decolagem(Fila*);

// c. Adicionar um avião à fila de espera (enfileirar)
void adiciona_espera(Aviao,Fila*);

// d. Listar todos os aviões na fila de espera (imprimir)
void fila_espera(Fila*);

// e. Listar as caracteristicas do primeiro aviao (buscar primeiro elemento)
void primeiro_aviao(Fila*);

// Outras funções necessárias
Fila* Inicializa();
void Esvaziar(Fila*);
int Vazia(Fila*);
Aviao Inicializa_aviao(char*, int);
void copia(char*, char*);
