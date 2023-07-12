#include "pista.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

  // Criar a fila
  Fila *fila;
  fila = Inicializa();
  Esvaziar(fila);

  int operacao;
  Aviao aviao;

  cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
  cout << "          PISTA DE DECOLAGEM" << endl;
  cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

  cout << endl;

  while (1) {

    cout << "Digite a tarefa a ser feita: " << endl;
    cout << "1 - Adicionar um aviao à fila de espera;" << endl;
    cout << "2 - Autorizar a decolagem do primeiro aviao da fila;" << endl;
    cout << "3 - Listar o numero de avioes aguardando na fila de decolagem;"
         << endl;
    cout << "4 - Listar todos os avioes na fila de espera;" << endl;
    cout << "5 - Listar as caracteristicas do primeiro aviao da fila;" << endl;
    cout << "6 - Finalizar operação" << endl;
    cout << "Digite sua escolha: " << endl;
    cin >> operacao;

    if (operacao == 6) {
      cout << "======= Sessão Finalizada =======" << endl;
      break;
    }

    else if (operacao == 1) {
      cout << "============================================" << endl;
      char nome[40];
      int identificador;
      cout << "                  CADASTRO" << endl;
      cout << "Digite o nome do Aviao: " << endl;
      cin.ignore();
      cin.get(nome,40);

      cout << "Digite o identificador: " << endl;
      cin >> identificador;

      aviao = Inicializa_aviao(nome, identificador);
      adiciona_espera(aviao, fila);

      cout << endl;

      cout << "Aviao adicionado à fila de espera !!!" << endl;
      cout << "============================================" << endl;
    }

    else if (operacao == 2) {
      cout << "============================================" << endl;
      cout << "                 DECOLAGEM" << endl;

      if (Vazia(fila)) {
        Aviao x;
        cout << "Nao ha avioes esperando para decolagem !" << endl;
      }

      else {
        aviao = decolagem(fila);

        cout << "Detalhes do aviao: " << endl;
        cout << "Nome: " << aviao.nome << endl;
        cout << "Identificador: " << aviao.identificador << endl;

        cout << endl;

        cout << "Aviao liberado com exito !!!" << endl;
      }
      cout << "============================================" << endl;
    }

    else if (operacao == 3) {
      cout << "============================================" << endl;
      cout << "     QUANTIDADE DE AVIOES NA FILA" << endl;

      cout << endl;

      cout << "Existem " << numero_fila(fila) << " avioes na fila de decolagem."
           << endl;
      cout << "============================================" << endl;
    }

    else if (operacao == 4) {
      cout << "============================================" << endl;
      cout << "             AVIOES NA FILA" << endl;

      cout << endl;

      fila_espera(fila);
      cout << "============================================" << endl;
    }

    else if (operacao == 5) {
      cout << "============================================" << endl;
      cout << "              PRIMEIRO AVIAO" << endl;

      cout << endl;

      primeiro_aviao(fila);
      cout << "============================================" << endl;
    }

    else {
      cout << "============================================" << endl;
      cout << "Comando inválido !!!" << endl;
      cout << "Tente novamente." << endl;
      cout << "============================================" << endl;
    }
  }
}

