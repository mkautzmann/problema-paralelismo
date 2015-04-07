//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "ProblemaFilosofos.h"


ProblemaFilosofos::ProblemaFilosofos() {

    int i;
    Messenger messenger;
    Filosofo* f;
    Garfo* g;

    // Cria os garfos
    for(i = 0; i < NUMERO_GARFOS; i++) {
        g = new Garfo();
        this->garfos.push_back(g);
    }

    // Cria os filosofos e começa o programa
    for(i = 0; i < NUMERO_FILOSOFOS; i++) {
        messenger.log("Filosofo " + std::to_string(i) + " sentou na mesa.");
        if(i == 0) {
            f = new Filosofo(i, this->garfos[i], this->garfos[NUMERO_GARFOS - 1], &messenger);
            this->filosofos.push_back(f);
        }
        else {
            f = new Filosofo(i, this->garfos[i], this->garfos[i - 1], &messenger);
            this->filosofos.push_back(f);
        }
    }
}

void ProblemaFilosofos::parar() {

    Filosofo::morre();

}