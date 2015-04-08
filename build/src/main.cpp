#include <iostream>
#include <stdlib.h>
#include <thread>
#include <vector>
#include "Messenger.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define Numero_Cadeiras 5

int cadeiras_disponiveis = Numero_Cadeiras;
bool barbeiro_acordado = true;
bool FecharBarbearia = false;
std::mutex cadeira_barbeiro;
Messenger* messenger;


void clientes(int id);
void barbeiro();
int fecharBarbearia();

void esperar(unsigned int segundos) {
	#ifdef _WIN32
	Sleep(segundos*1000);
	#else
	sleep(segundos);
	#endif
}

int main(int argc, char *argv[]) {
    int i = 0;

	messenger->log("Iniciando problema do barbeiro dorminhoco. Pressione enter para fechar a barbearia ou espere 30 clientes serem atendidos...");

	// Cria thread que verifica o enter
	std::thread leitura;
	leitura = std::thread(fecharBarbearia);
	leitura.detach();

	// Cria o Barbeiro
	std::thread barbeiro1;
	barbeiro1 = std::thread(barbeiro);

    // Cria os clientes
	std::vector<std::thread> cliente;
	while(!FecharBarbearia) {
		srand(time(NULL));
		cliente.push_back(std::thread(clientes, i));
		messenger->log("Cliente " + std::to_string(i) + " criado.");
		i++;
		esperar(rand() % 15);
	}

	// Espera o ciclo do barbeiro acabar
	barbeiro1.join();

	// Espera todos os clientes encerrarem suas atividades
	for(int j = 0; j < i; j++) {
		cliente[j].join();
	}

	messenger->log("Barbearia fechada, pressione enter para encerrar o programa.");
	messenger->log("Clientes criados no total: " + std::to_string(i));

	getchar();

	messenger->log("Programa terminado!");

	exit(0);
}

void clientes(int id) {
    if (cadeiras_disponiveis >= 1){
		messenger->print("Cliente " + std::to_string(id) + " esperando.");

	 	cadeiras_disponiveis--;
		cadeira_barbeiro.lock();

   	messenger->print("Cliente " + std::to_string(id) + " esta sendo atendido.");

   	cadeiras_disponiveis++;

		messenger->print("Cliente " + std::to_string(id) + " foi embora");
    cadeira_barbeiro.unlock();

 	}
 	else{
 		messenger->print("Cliente " + std::to_string(id) + " foi embora por falta de espaco.");
	 }

}

void barbeiro(){
  	while (!FecharBarbearia) {
		srand(time(NULL));
		if (barbeiro_acordado){
  			if (cadeiras_disponiveis == Numero_Cadeiras){
  				messenger->print("Barbeiro dormiu");
					barbeiro_acordado = false;
  			}
			else{

				messenger->print("Barbeiro iniciou o corte");

	  		esperar(rand() % 10);

				messenger->print("Barbeiro terminou o corte.");
			}

		}
		else if ((cadeiras_disponiveis < Numero_Cadeiras)){
			messenger->print("Barbeiro acordou");
			barbeiro_acordado = true;
		}
	}
}

int fecharBarbearia() {
	getchar();
	messenger->log("Fechando barbearia...");
	FecharBarbearia = true;
	return 0;
}
