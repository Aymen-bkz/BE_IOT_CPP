#include "ESP86_server.h"
#include "init.h"


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            {
              Serial.printf("[%u] Disconnected!\n", num);
              break;
            }
            
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
                gameInit game;
                Serial.println(game.json.gameover);
                while(!game.json.gameover){
                  game.gameLoop();
                }
                
                //if(triger) Timer.attach_ms(1000, +[] () { Serial.println("test void"); });
                //game_init.gameLoop();       
                // send message to client
                //webSocket.sendTXT(num, "Connected");
                break;
            }
            
        case WStype_TEXT:
            {
              Serial.printf("[%u] get Text: %s\n", num, payload);
                // send message to client
                // webSocket.sendTXT(num, "message here");
                //game_init.json.gameover = false;
                //Serial.println(game_init.json.gameover);
                // send data to all connected clients
                // webSocket.broadcastTXT("message here");
                break;
            }
        case WStype_BIN:
            {
              Serial.printf("[%u] get binary length: %u\n", num, length);
                hexdump(payload, length);
    
                // send message to clients
                // webSocket.sendBIN(num, payload, length);
                break;
            }
            
    }
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  init_server();
  ESP86_accelometer_setup();
  ESP86_webSocket_setup();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  webSocket.loop();  
  delay(5);
}
