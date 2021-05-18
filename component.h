#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
using namespace std;

class component {
    public:
        string type;
        component(string type);
        ~component(){};
};


#endif