#include "WiFi.h"
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(10);
Serial.println("Setup Done");
}


void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Start Scan");
int n = WiFi.scanNetworks();
Serial.println("Scan Done");
if(n == 0){
  Serial.println("NO CONNECTIONS");
}
else{
  Serial.print(n);
  Serial.println(" Connections Available");
  for(int i=0 ; i<n ; i++){
    Serial.print(i + 1);
    Serial.print(" : ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" ( " );
    Serial.print(WiFi.RSSI(i));
    Serial.print(" ) ");
    Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
    delay(100); 
  }
}
Serial.println();
delay(7000);
}
