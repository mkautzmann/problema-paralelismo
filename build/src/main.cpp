/*
	Implementação de uma solução para os problemas de paralelismo usando threads: filósofos famintos e barbeiro dorminhoco.
	Autores: Gustavo Willrich e Matheus Kautzmann
	Linguagem: C++ usando C++11
	Licença: MIT	
*/

// Inclusão das bibliotecas necessárias
#include <iostream>
#include <thread>
#include "ProblemaFilosofos.h"

void encerrar();

ProblemaFilosofos* p1;

Messenger* messenger;

int main(int argc, char* argv[]) {

  messenger->log("Iniciando o problema dos filósofos. Pressione enter para parar a execução e ver o relatório.");
  messenger->log("");

  p1 = new ProblemaFilosofos();

  std::thread t1 (encerrar);

  t1.join();

  delete p1;

  getchar();

  messenger->log("Programa terminado!");

  return 0;
}

void encerrar() {
  getchar();
  messenger->log("Encerrando loops de vida dos filosofos, aguarde os resultados e depois pressione enter para encerrar o programa");
  messenger->log("");
  p1->parar();
}