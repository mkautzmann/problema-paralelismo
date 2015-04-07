//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "Filosofo.h"

// Todos compartilham o status de vivo ou morto
static bool vivo = true;

__thread int id;
__thread Garfo* garfoEsquerda;
__thread Garfo* garfoDireita;
__thread int vezesComeu = 0;
__thread int estado = Filosofo::EstadoFilosofo::NOVO;

Filosofo::Filosofo(int id, Garfo* garfoEsquerda, Garfo* garfoDireita, Messenger* messenger) {
    messenger->log("Filosofo " + std::to_string(id) + " começará suas atividades.");
    this->tFilosofo = std::thread(&Filosofo::vive, this, id, garfoEsquerda, garfoDireita);
};

void Filosofo::vive(Filosofo *ctx, int _id, Garfo* ge, Garfo* gd) {
    id = _id;
    garfoEsquerda = ge;
    garfoDireita = gd;
    sleep(1);
    while(vivo) {
        pensa(ctx);
        if(pega_garfos()) {
            come(ctx);
            solta_garfos();
        }
    }
    int v = 0;
    v += vezesComeu;
    std::string msg = "";
    if(v != 1)
        msg = "Resultado! Filosofo " + std::to_string(_id) + " comeu " + std::to_string(v) + " vezes!";
    else
        msg = "Resultado! Filosofo " + std::to_string(_id) + " comeu " + std::to_string(v) + " vez!";
    messenger->print(msg);
}

void Filosofo::come(Filosofo *ctx) {
    estado = Filosofo::EstadoFilosofo::COMENDO;
    ctx->messenger->print("Filosofo " + std::to_string(id) + " comendo...");
    vezesComeu++;
    sleep(2);
}

void Filosofo::pensa(Filosofo *ctx) {
    srand(time(NULL));
    int tempo = rand() % 10;
    estado = Filosofo::EstadoFilosofo::PENSANDO;
    ctx->messenger->print("Filosofo " + std::to_string(id) + " pensando...");
    sleep(2);
}

bool Filosofo::pega_garfos() {
    //messenger->print("Filosofo " + std::to_string(id) + " está com fome!");
    estado = Filosofo::EstadoFilosofo::FOME;
    if(pega_garfo(garfoEsquerda)) {
        if(pega_garfo(garfoDireita)) {
            return true;
        }
        else {
            solta_garfo(garfoEsquerda);
        }
    }
    return false;
}

void Filosofo::solta_garfos() {
    solta_garfo(garfoEsquerda);
    solta_garfo(garfoDireita);
}

bool Filosofo::pega_garfo(Garfo* garfo) {
    if(garfo->getEstado() == Garfo::EstadoGarfo::LIVRE) {
        return garfo->usar();
    }
    return false;
}

void Filosofo::solta_garfo(Garfo* garfo) {
    garfo->liberar();
}

bool Filosofo::morre() {
    vivo = false;
    return true;
}

