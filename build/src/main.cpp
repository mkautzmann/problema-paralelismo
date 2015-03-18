/*
	Implementação de uma solução para os problemas de paralelismo usando threads: filósofos famintos e barbeiro dorminhoco.
	Autores: Gustavo Willrich e Matheus Kautzmann
	Linguagem: C++ usando C++11
	Licença: MIT	
*/

// Inclusão das bibliotecas necessárias
#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

// Definição de constantes do projeto
#define NUMERO_FILOSOFOS 5

// Define funções utilizadas no projeto
void filosofar(int id);


// TODO: Implementar a navegação entre os problemas e a ligação das funções
int main(int argc, char* argv[]) {

  thread filosofos[NUMERO_FILOSOFOS];
  
  for(int i = 0; i < NUMERO_FILOSOFOS; i++) {
    filosofos[i] = thread(filosofar, i);
  }
  
  for(int i = 0; i < NUMERO_FILOSOFOS; i++)
    filosofos[i].join();
  
  cout << "Todas as threads abriram e terminaram";

  return 0;
}

// TODO: Implementar a verdadeira função
void filosofar(int id) {
	sleep(id);
}