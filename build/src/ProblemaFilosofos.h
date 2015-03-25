//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_PROBLEMAFILOSOFOS_H_
#define _BUILD_PROBLEMAFILOSOFOS_H_

#define NUMERO_FILOSOFOS 5
#define NUMERO_GARFOS NUMERO_FILOSOFOS

#import "Filosofo.h"
#import "Garfo.h"

class ProblemaFilosofos {
    private:
        Filosofo filosofos[NUMERO_FILOSOFOS];
        Garfo garfos[NUMERO_GARFOS];
    public:
        void executar();
        void parar();
};


#endif //_BUILD_PROBLEMAFILOSOFOS_H_
