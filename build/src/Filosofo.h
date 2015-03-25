//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_FILOSOFO_H_
#define _BUILD_FILOSOFO_H_

#include <thread>
#include "Garfo.h"

class Filosofo {

    private:
        bool vivo;
        int vezesComeu;
        int estado;
        std::thread thread;
        enum EstadoFilosofo { NOVO, COMENDO, PENSANDO };
        void vive();
        void come();
        void pensa();
        bool pega_garfos();
        void solta_garfos();
        bool pega_garfo(int idx);
        void solta_garfo(int idx);
    public:
        Filosofo(Garfo* garfoEsquerda, Garfo* garfoDireita);
        bool morre();

};


#endif //_BUILD_FILOSOFO_H_
