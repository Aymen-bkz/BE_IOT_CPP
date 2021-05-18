  #ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <Wire.h>
#include "MMA7660.h"
#include "JSON.h"

MMA7660 accelemeter;


void ESP86_accelometer_setup();
void set_json_xyz(JSON& json);

void set_json_xyz(JSON& json) {

  float ax,ay,az;
  accelemeter.getAcceleration(&ax,&ay,&az);
  ax = -ax*20;
  ay = -ay*20;
  az = -az*20;
  json.ax = (int)ax;
  json.ay = (int)ay;
  json.az = (int)az;
  
  //Serial.printf("x:%f y:%f z:%f \n", ax, ay, az);
  //Serial.printf("x:%d y:%d z:%d \n", json.ax, json.ay, json.az);
}

void ESP86_accelometer_setup() {
  accelemeter.init();
}


#endif
