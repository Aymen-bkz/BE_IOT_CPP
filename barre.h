#ifndef Barre_H
#define Barre_H

#include "component.h"
#include "JSON.h"

#define BARRE_MARGIN_BOTTOM 20;

class Barre: public component {
    private:
        
        int h, w, x, y, dx;
        string color;
    public:
        Barre();
        ~Barre() {};
        void setBarre(int w, int h, JSON& json, string color);
        void set_speed(int s);
        void set_json_barre(JSON& json);
        void barreMove(JSON& json);
        void setReset(JSON& json);
};


#endif
