//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_GARFO_H_
#define _BUILD_GARFO_H_


class Garfo {
    private:
        int emUso;
    public:
        enum EstadoGarfo { OPUPADO, LIVRE };
        int estaEmUso();
        void usar();
        Garfo();
};


#endif //_BUILD_GARFO_H_
