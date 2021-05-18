#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "ESP86_accelerometer.h"
#include <WebSocketsServer.h>

WebSocketsServer webSocket = WebSocketsServer(81);

void ESP86_webSocket_setup();
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);


void ESP86_webSocket_setup() {
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}


#endif
