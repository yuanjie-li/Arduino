#include <WiFiNINA.h>
#include <ArduinoJson.h>

#include "secrets.h"

// WiFi Info 
char ssid[] = SECRET_SSID;        
char pass[] = SECRET_PASS;        
int status = WL_IDLE_STATUS;     
WiFiClient client;
  

void setup() {
  while (!Serial);

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
       
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);

  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");

  Serial.println("----------------------------------------");
  printWifi();
  Serial.println("----------------------------------------");
  
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Connect to the API server 
  client.connect("192.168.50.3", 8000);
}

void loop() {
  
  // check the network connection:
  printWifi();
  Serial.println("----------------------------------------");

  // Capacitive 
  int capValue = analogRead(A0);
  Serial.println(capValue);
  sendData(capValue, 1);

  delay(1000);        // delay in between reads for stability
}

void printWifi() {
  Serial.println("Board Information:");
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.println();
  Serial.println("Network Information:");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

}

void sendData(int value, int device_id) {
  
  const char* endPoint = "http://192.168.50.3/postgresDb/create/measurements";

  
  // Send request
}