#include<WiFi.h>

const char* ssid = "Abhi Ram";
const char* password = "9676959922";

WiFiServer server(80);
String header;

const int Output26 = 26;
const int Output27 = 27;

String Output26state = "off";
String Output27state = "off";

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeout = 2000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

pinMode(Output26 ,OUTPUT);
pinMode(Output27 ,OUTPUT);
digitalWrite(Output26 ,LOW);
digitalWrite(Output27 ,LOW);

Serial.print("Connecting to:");
Serial.print(ssid);
WiFi.begin(ssid,password);
while(WiFi.status() != WL_CONNECTED){
  delay(50);
  Serial.print(".");
  }
Serial.println("Connection established");
Serial.print("IP Address:");
Serial.print(WiFi.localIP());
server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client = server.available();

if(client){
  currentTime = millis();
  previousTime = currentTime;
  Serial.print("NEW CLIENT");
  String currentLine = "";
  while(client.connected() && currentTime-previousTime <= timeout){
    currentTime = millis();
    if(client.available()){
      char c = client.read();
      Serial.write(c);
      header += c;
      if(c == '\n'){
        if(currentLine.length() == 0){
          client.println("HTTP/1.1 200 OK");
          client.println("content-type:text/html");
          client.println("connection:close");
          client.println();
          if(header.indexOf("GET/26/ON") >= 0){
            Serial.println("GPIO 26 ON");
            Output26state = "on";
            digitalWrite(Output26,HIGH); 
          }
          else if(header.indexOf("GPIO/26/OFF") >= 0){
            Serial.println("GPIO 26 OFF");
            Output26state = "off";
            digitalWrite(Output26 , LOW);
          }
          else if(header.indexOf("GPIO/27/ON") >= 0){
            Serial.println("GPIO 27 ON");
            Output27state = "on";
            digitalWrite(Output27,HIGH);
          }
          else if(header.indexOf("GPIO/27/OFF") >= 0){
            Serial.println("GPIO 27 OFF");
            Output27state = "off";
            digitalWrite(Output27,LOW);
          }

          client.println("<!DOCTYPE><html>");
          client.println("<head><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          client.println("<style>html{font-family:Helvetica;display:inline-block;margin:0px auto;text-align:center;}");
          client.println(".button{background-color:#4CAF50;border:none;color:white:padding:16px 40px;");
          client.println("text-decoration:none;font-size:30px;margin:2px:cursor:pointer;}");
          client.println(".button2{background-color:#555555;}</style></head>");
          client.println("<body><h1>ESP32 WebServer</h1>");
          client.println("<p>GPIO26 - State\" + Output26state + \"</p>");
          if(Output26state = "off"){
            client.println("<p><a href = \"/26/on\"><button class=\"button\">ON</button></a></p>"); 
          }
          else if(Output26state = "on"){
            client.println("<p><a href = \"/26/off\"><button class=\"button\">OFF</button></a></p>");
          }
          client.println("<p>GPIO - State\" + Output27state + \"</p>");
          if(Output27state = "off"){
            client.println("<p><a href = \"/27/on\"><button class=\"button\">ON</button></a></p>");
          }
          else if(Output27state = "on"){
            client.println("<p><a href= \"27/off\"><button class=\"button\">OFF</button></a></p>");
          }
          client.println("</body></html>");
          client.println();
          break;
        }
        else{
          currentLine = "";
        } 
      }
      else if (c!='\r'){
      currentLine += c;   
      }
    }
  }
header = "";
client.stop();
Serial.println("Client Disconnected");
Serial.println("");
}
}
