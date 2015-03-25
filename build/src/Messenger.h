//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_MESSENGER_H_
#define _BUILD_MESSENGER_H_

#import <string>
#import <mutex>
#import <iostream>

class Messenger {
    private:
        std::mutex lock;
    public:
        void print(std::string value);
};


#endif //_BUILD_MESSENGER_H_
