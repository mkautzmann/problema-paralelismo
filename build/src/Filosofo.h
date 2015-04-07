//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_FILOSOFO_H_
#define _BUILD_FILOSOFO_H_

#import <thread>
#import "unistd.h"
#import "Garfo.h"
#import "Messenger.h"

class Filosofo {
    private:
        static Messenger* messenger;
        static void come(Filosofo *ctx);
        static void pensa(Filosofo *ctx);
        static bool pega_garfos();
        static void solta_garfos();
        static bool pega_garfo(Garfo* garfo);
        static void solta_garfo(Garfo* garfo);
    public:
        enum EstadoFilosofo { NOVO, COMENDO, PENSANDO, FOME };
        std::thread tFilosofo;
        Filosofo(int id, Garfo* garfoEsquerda, Garfo* garfoDireita, Messenger* messenger);
        static void vive(Filosofo *ctx, int id, Garfo* ge, Garfo* gd);
        static bool morre();
};


#endif //_BUILD_FILOSOFO_H_
