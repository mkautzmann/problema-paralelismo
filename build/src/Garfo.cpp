//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "Garfo.h"

Garfo::Garfo() {
    this->emUso = EstadoGarfo::LIVRE;
}

int Garfo::estaEmUso() {
    return this->emUso;
}

void Garfo::usar() {
    this->emUso = EstadoGarfo::OPUPADO;
}