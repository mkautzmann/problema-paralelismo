//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "Garfo.h"

Garfo::Garfo() {
    this->emUso = EstadoGarfo::LIVRE;
}

int Garfo::getEstado() {
    return this->emUso;
}

bool Garfo::usar() {
    tranca.lock()
    if(this->getEstado() == EstadoGarfo::LIVRE) {
        this->emUso = EstadoGarfo::OPUPADO;
        return true;
    }
    tranca.unlock();
    return false;
}

void Garfo::liberar() {
    this->emUso = EstadoGarfo::LIVRE;
}