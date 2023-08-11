#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID   "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourBlynkAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "*********";
char pass[] = "*********";

BLYNK_WRITE(V0){
  if(param.asInt()==1){
    digitalWrite(4, LOW);
  }
  else{
    digitalWrite(4, HIGH);
  } 
  }

  BLYNK_CONNECTED(){
    Blynk.syncVirtual(V0);
  }
  
void setup()
{
  // Debug console
  pinMode(4, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
