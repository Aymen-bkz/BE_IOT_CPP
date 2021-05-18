#ifndef INIT_H
#define INIT_H

#include <exception>
#include <string>
#include "JSON.h"
#include "barre.h"
#include "ball.h"
#include "Area.h"
#include "briques.h"
#include "ESP86_accelerometer.h"
#include "ESP86_webSocket.h"
#include <Ticker.h>
Ticker Timer;



class gameInit {
    public:
        JSON json;
        Area area;
        Barre barre;
        Ball ball;
        Briques briques;       

        gameInit();
        ~gameInit(){};
        void gameLoop();
        void process(int ms);
        void gameOver();
        void resetGame();
};

gameInit:: gameInit() {
    set_json_xyz(this->json);

    this->briques.r = 2;
    this->briques.setBriques();
    this->json.b_array = briques.b_array;
  
    this->area.setArea(600, 500);
    this->area.set_json_area(json);

    this->barre.setBarre(100, 10, this->json, "#fff");
    this->barre.set_json_barre(this->json);

    this->ball.setBall(5, this->json, "blue");
    this->ball.set_json_ball(this->json);

    this->json.set_init_json();
    webSocket.sendTXT(0, this->json.get_json_data().c_str());
    delay(20);
    this->json.set_json();
    webSocket.sendTXT(0, this->json.get_json_data().c_str());
    delay(20);
}

void gameInit:: gameLoop() {
        set_json_xyz(this->json);
  
        this->barre.set_speed(this->json.ay);
        this->barre.barreMove(this->json);
        this->barre.set_json_barre(this->json);

        this->ball.set_ball_speed(20);
        this->ball.moveBall();
        this->ball.bwCollision(this->json);
        this->ball.bbCollision(this->json);
        this->ball.brCollision(this->json);
        this->ball.set_json_ball(this->json);

        if(this->json.reset) {
          this->resetGame();
        }

        this->gameOver();
        
        this->json.set_json();
        webSocket.sendTXT(0, this->json.get_json_data().c_str());
        delay(20);
        //this->json.display();

  
}

void gameInit:: gameOver() {
  try{
    unsigned short c = 0;
    if(c != 0) {
      cout << c << endl;
    }
    for(size_t i=0; i<this->briques.b_array.size(); i++) {
        if(!json.b_array[i].status) {
          c++;
          if(c == this->briques.b_array.size()) {
            throw string("GAMEOVER");
          }
        }
    }
  }
  catch(string const& s) {
    cout << s << endl;
    this->json.gameover = true;
  }
   
}

void gameInit:: resetGame() {
        this->json.score = 0;
        
        this->briques.b_array.clear();
        this->json.b_array.clear();
        this->briques.r = 1;
        this->briques.setBriques();

        this->json.b_array = briques.b_array;
        this->json.clear_brique = -1;
        
        this->barre.setReset(this->json);
        this->barre.set_json_barre(this->json);
        
        this->ball.setReset(this->json);
        this->ball.set_json_ball(this->json);          

        this->json.set_json();
        webSocket.sendTXT(0, this->json.get_json_data().c_str());
        delay(20);
        
        this->json.set_init_json();        
        webSocket.sendTXT(0, this->json.get_json_data().c_str());
        delay(20);
}

#endif
