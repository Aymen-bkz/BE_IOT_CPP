#ifndef JSON_H
#define JSON_H
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "briques.h"
#include <string>
#include <iostream>

using namespace std;
using namespace rapidjson;

class JSON {
  private:
    StringBuffer data;
  public:
    int area_w, area_h;
    int barre_w, barre_h, barre_x, barre_y, barre_dx, barre_speed;
    int ball_r, ball_x, ball_y, ball_dx, ball_dy, ball_speed;
    int score = 0;
    int clear_brique = -1;
    float ball_angle;
    int ax,ay,az;
    bool clear, reset;
    bool gameover = false;
    bool triger = false;
    string barre_color,ball_color, ball_sens;
    vector<Briques> b_array;
    
    JSON();
    ~JSON() {};
    void set_init_json();
    void set_json();
    void display();
    string get_json_data();

    vector<Briques> operator= (vector<Briques> array);
};

#endif
