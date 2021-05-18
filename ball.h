#ifndef BALL_H
#define BALL_H

#include <math.h>
#include "component.h"
#include "JSON.h"

class Ball: public component
{
    private:
        int r, x, y, speed, dx, dy;
        float angle;
        string color;
        bool reset = false;
    public:
        Ball();
        ~Ball() {};
        void setBall(int r, JSON& json, string color);
        void set_json_ball(JSON& json);
        void set_ball_speed(int s);
        void moveBall();
        void setReset(JSON& json);
        void bwCollision(JSON& json);
        void bbCollision(JSON& json);
        void brCollision(JSON& json);
};

#endif
