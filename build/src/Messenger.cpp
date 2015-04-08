//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "Messenger.h"

std::mutex semaforo;

int grupo = 0;

void Messenger::print(std::string value) {
    semaforo.lock();
    std::cout << value << std::endl;
    grupo++;
    if(grupo == 5) {
        std::cout << std::endl;
        grupo = 0;
    }
    semaforo.unlock();
}

void Messenger::log(std::string value) {
    semaforo.lock();
    std::cout << value << std::endl;
    semaforo.unlock();
}