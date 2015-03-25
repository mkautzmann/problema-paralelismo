//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "ProblemaFilosofos.h"


void ProblemaFilosofos::executar() {

    // Cria os garfos
    for(int i = 0; i < NUMERO_GARFOS; i++) {
        this->garfos[i] = Garfo::Garfo();
    }

    // Cria os filosofos e começa o programa
    for(int i = 0; i < NUMERO_FILOSOFOS; i++) {
        if(i == 0)
            this->filosofos[i] = Filosofo::Filosofo(&this->garfos[i], &this->garfos[NUMERO_GARFOS - 1]);
        else
            this->filosofos[i] = Filosofo::Filosofo(&this->garfos[i], &this->garfos[i - 1]);
    }

}

void ProblemaFilosofos::parar() {

    //TODO: Implementar a parada das threads e do programa

    for(auto filosofo : this->filosofos) {
        filosofo.morre();
    }

}