#include "Barre.h"

Barre:: Barre(): component("Barre"){}

void Barre:: setBarre(int w, int h, JSON& json, string color) {
    this->w = w;
    this->h = h;
    this->x = json.area_w/2 - w/2;
    this->y = json.area_h - h - BARRE_MARGIN_BOTTOM;
    this->dx = 8;
    this->color = color;
}

void Barre:: set_speed(int s) {
    this->dx = s;
}

void Barre:: set_json_barre(JSON& json) {
    json.barre_w = this->w;
    json.barre_h = this->h;
    json.barre_x = this->x;
    json.barre_y = this->y;
    json.barre_dx = this->dx;
    json.barre_color = this->color;
}

void Barre:: barreMove(JSON& json) {
    this->x += this->dx;
    if(this->x + this->w > json.area_w) this->x = json.area_w - this->w;
    if(this->x < 0) this->x = 0;
}

void Barre:: setReset(JSON& json) {
  this->x = (int)(json.area_w/2 - this->w/2);
  this->y = json.area_h - this->h - BARRE_MARGIN_BOTTOM;
}
