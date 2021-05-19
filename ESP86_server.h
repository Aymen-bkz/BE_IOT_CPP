  #ifndef SERVER_H
#define SERVER_H
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "game_html.h"

ESP8266WebServer server;
void handleRoot();
void init_server();
void init_access_point();


void handleRoot() {
  server.send(200, "text/html", html_1);   // Send HTTP status 200 (Ok) and send some text to the browser/client
}


void init_server() {
  char ssid[] = "AndroidAPBD99";  // use your own network ssid and password
  char pass[] = "chks9274"; 
	// Connect to a WiFi network	Serial.print(F("Connecting to "));  Serial.println(ssid);
	WiFi.begin(ssid, pass);

	// connection with timeout
	int count = 0;
	while ( (WiFi.status() != WL_CONNECTED) && count < 17)
	{
	Serial.print(".");  delay(500);  count++;
	}

	if (WiFi.status() != WL_CONNECTED)
	{
	Serial.println("");  Serial.print("Failed to connect to ");  Serial.println(ssid);
	while (1);
	}

	Serial.println("");
	Serial.println(F("[CONNECTED]"));   Serial.print("[IP ");  Serial.print(WiFi.localIP());
	Serial.println("]");

	// start a server
	server.on("/", handleRoot);
	server.begin();
	Serial.println("Server started");
}


void init_access_point() {
  char ssid[] = "ESP8622";  // use your own network ssid and password
  char pass[] = "12345678";
  IPAddress ip(192,168,11,4); // arbitrary IP address (doesn't conflict w/ local network)
  IPAddress gateway(192,168,11,1);
  IPAddress subnet(255,255,255,0);

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(ip, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid,pass) ? "Ready" : "Failed!");
  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());

  // start a server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Server started");
}


#endif
