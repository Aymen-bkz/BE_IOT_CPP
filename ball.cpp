#include "ball.h"

Ball:: Ball(): component("ball") {};

void Ball:: setBall(int r, JSON& json, string color) {
    this->r = r;
    this->x = json.area_w/2;
    this->y = json.barre_y - r;
    this->dx = 1;
    this->dy = -5;
    this->angle = 5;
    this->color = color;
    this->speed = 5;
    this->reset = false;
}

void Ball:: set_json_ball(JSON& json) {
    json.ball_r = this->r;
    json.ball_x = this->x;
    json.ball_y = this->y;
    json.ball_dx = this->dx;
    json.ball_dy = this->dy;
    json.ball_angle = this->angle;
    json.ball_color = this->color;
    json.ball_speed = this->speed;
    json.reset = this->reset;
}

void Ball:: set_ball_speed(int s) {
    this->speed = s;
}

void Ball:: moveBall() {
    this->x += this->dx;
    this->y += this->dy;
}

void Ball:: setReset(JSON& json) {
  this->x = (int)(json.area_w/2);
  this->y = json.barre_y - json.ball_r;
  this->reset = false;
}

void Ball:: bwCollision(JSON& json) {
  if(this->x + this->r > json.area_w || this->x - this->r < 0) {
    this->dx *= -1;
  }
  else if(this->y - this->r < 0) {
    this->dy *= -1;
  }
  else if(this->y + this->r > json.area_h) {
    this->reset = true;
  }
}

void Ball:: bbCollision(JSON& json) {
  if(this->x + this->r > json.barre_x && this->x - this->r < (json.barre_x + json.barre_w) && this->y + this->r > json.barre_y) {
    float crashPoint = this->x - (json.barre_x + json.barre_w/2);
    //cout << " crsh: " << crashPoint << " json.barre_w/2: "<< json.barre_w/2  << endl;
    crashPoint = (crashPoint*2)/(json.barre_w/2);
    this->angle = crashPoint * M_PI/3;
    this->dx = (int) (this->speed/3 * sin(this->angle)+2);
    this->dy = (int) (this->speed/2 * cos(this->angle)+2);
    if(this->dy > 0 ) this->dy *= -1;
    //cout << "ang: " << this->angle << " crsh: " << crashPoint << " dy: " << this->dy << " dx: " << this->dx << endl;
  }
}

void Ball:: brCollision(JSON& json){
  for(size_t i=0; i<json.b_array.size(); i++) {
    if(json.b_array[i].status) {
      if((this->x + this->r) > json.b_array[i].x && (this->x - this->r) < (json.b_array[i].x + json.b_array[i].w) &&
        (this->y + this->r) > json.b_array[i].y && (this->y - this->r) < (json.b_array[i].y + json.b_array[i].h)
      ) {
          this->dy *= -1;
          json.clear_brique = i;
          json.b_array[i].status = false;
          json.score += 100;
       }
    }
  }
}
