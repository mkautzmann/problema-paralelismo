//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "Filosofo.h"

Filosofo::Filosofo(Garfo* garfoEsquerda, Garfo* garfoDireita) {
    this->vivo = true;
    this->vezesComeu = 0;
    this->thread = std::thread(vive);
}

void Filosofo::vive() {
    while(this->vivo) {
        this->pensa();
        this->pega_garfos();
        this->come();
        this->solta_garfos();
    }
}

void Filosofo::come() {

}

void Filosofo::pensa() {

}

bool Filosofo::pega_garfos() {
    return true;
}

void Filosofo::solta_garfos() {}

bool Filosofo::pega_garfo(int idx) {
    return true;
}

void Filosofo::solta_garfo(int idx) {

}

bool Filosofo::morre() {
    this->vivo = false;
    return !this->vivo;
}

