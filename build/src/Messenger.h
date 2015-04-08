//
// Created by Matheus Kautzmann on 25/03/15.
//

#ifndef _BUILD_MESSENGER_H_
#define _BUILD_MESSENGER_H_

#include <string>
#include <mutex>
#include <iostream>

class Messenger {
  public:
    static void print(std::string value);
    static void log(std::string value);
};

#endif //_BUILD_MESSENGER_H_
