//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_PROBLEMAFILOSOFOS_H_
#define _BUILD_PROBLEMAFILOSOFOS_H_

#define NUMERO_FILOSOFOS 5
#define NUMERO_GARFOS NUMERO_FILOSOFOS

#include <vector>
#include "Messenger.h"
#include "Filosofo.h"
#include "Garfo.h"

class ProblemaFilosofos {
    private:
        std::vector<Filosofo*> filosofos;
        std::vector<Garfo*> garfos;
    public:
        ProblemaFilosofos();
        void parar();
};


#endif //_BUILD_PROBLEMAFILOSOFOS_H_
