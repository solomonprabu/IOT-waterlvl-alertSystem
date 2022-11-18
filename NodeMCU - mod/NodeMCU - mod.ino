#include <ESP8266WiFi.h>
const char *ssid="Solo";
const char *pass="qwer1234";
const char* host = "maker.ifttt.com";
int val;
char a;
String strs;
WiFiClient client;
void setup() {
Serial.begin(115200);
delay(10);
Serial.println("connecting to");
Serial.println(ssid);
WiFi.begin(ssid,pass);
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println(" ");
Serial.println("WiFi connected");
Serial.println("IP address:");
Serial.println(WiFi.localIP());
}

void loop() {
     const int httpPort = 80;  
      if (!client.connect(host, httpPort)) 
      {  
         Serial.println("connection failed");  
         return;
      } 
if(Serial.available())
      {
         a=Serial.read();  
         delay(500);
         if (a<='0.10' && a>=0.07)
        {    
            String url = "/trigger/sms/json/with/key/g_QjutMSaJeHKkyxU5szX1sEzSCSlTGb_0XJNiuHnhW"; 
            Serial.print("Requesting URL: ");
            Serial.println(url);              
            delay(500);   
            client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n"); 
         
          }                     
          else
          {
            Serial.println("Correct character not pressed.Try again");
            delay(1000);
          }
      }
}