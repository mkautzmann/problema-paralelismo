//
// Created by Matheus Kautzmann on 25/03/15.
//

#include "Messenger.h"

void Messenger::print(std::string value) {
    lock.lock();
    std::cout << value << std::endl;
    lock.unlock();
}