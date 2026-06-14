#include <WiFiNINA.h>

#include "secrets.h"

// WiFi Info 
char ssid[] = SECRET_SSID;        
char pass[] = SECRET_PASS;        
int status = WL_IDLE_STATUS;     

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
  printData();
  Serial.println("----------------------------------------");
  
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  
  // check the network connection:
  printData();
  Serial.println("----------------------------------------");

  // Capacitive 
  int capValue = analogRead(A0);
  Serial.println(capValue);
  
  // Resistive  
  int resValue = analogRead(A1);
  Serial.println(resValue);
  
  delay(100);        // delay in between reads for stability
}

void printData() {
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