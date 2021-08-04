//***************This data must be filled in by the user*******************************
const char* Profile = "----------";  // The same profile name on http://sanusb.org/espgpio
const char* ssid = "-----------";   // Wifi 
const char* password = "-----------";
//*************************************************************************************

#include "EspGpio.h"

const int led = 2; //builtin led
const int TIME_CHECK_UP = 5000; // ms only to test
int addr = 255, val = 0;
unsigned long b, c;

void wifi_config(void) {
  Serial.println();
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
  WiFi.begin(ssid, password);
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to Wifi AP...");
    for (int i = 0; i < 300; i++) { //try to connect to WiFi for max 30s
      if (WiFi.status() == WL_CONNECTED) {
        Serial.printf("it is connected after %d seconds", (i / 10));
        break;
      }
      yield();
      delay(100);
    }
  }
  if (WiFi.status() == WL_CONNECTED) {
    delay(100);
    Serial.println("\nconnected...yesss! :)");
    Serial.print("Current Profile = ");
    Serial.println(String(Profile));
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    EspGpio.sethost();
  } else {
    Serial.println("TimeOut! Not Connected even after 10 Seconds trying...\n *** Something wrong happened. It did not connected... *** ");
  }
}

void firebase_config(void) {

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Enable auto reconnect the WiFi when connection lost
  Firebase.reconnectWiFi(true);
}
//***********************************************************
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  //EEPROM.begin(256);
  wifi_config();
  firebase_config();  
//***********************************************************
  UploadOK = String(Profile);
  UploadOK.concat("OK");
  Serial.print("UploadOK = "); 
  Serial.println(UploadOK);
}
//**********************************************************
void loop() {
 // EspCloudUpdate.esp_update();

    if (Firebase.getInt(firebaseData, Profile)) //Success
  {
    Serial.print("Abs value = ");    
    c = firebaseData.intData();
    Serial.println(c);
  } else {
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }
delay(2000);

/* 
 *  b é um número inteiro par representado pela soma de potências de 2 para acionamento de conjunto de pinos. 
 * Evitar utilizar o pino Gpio 1 no Nodemcu ESP8266 que é o pino Tx, pois impede a comunicação serial de depuração 
 * do programa pelo monitor serial, e os pinos Gpio de 06 a 11 no ESP32 Devkit, pois são utilizados para a gravação flash.  
 * Se houver alguma falta de alimentação ou queda de energia e, em seguida, voltar ao normal, o estado dos pinos anterior   
 * à queda de tensão é restaurado, pois estado dos pinos são atualizados e consultados no Firebase, que é um banco de 
 * dados persistente.
 */
//*
    b=c;
    for (int k=40; k>=1; k--) {
        if (b>=pow(2,k)){
                       b=b-pow(2,k);
                                              
                       if (flagOn[k] != 1){ //só executa o pino desligado
                       pinMode(k, OUTPUT); //define o pino como saída(output)
                       digitalWrite(k, HIGH);
                        Serial.printf("Pin On: %lu\n", k);
                        flagOn[k]=1;
                         //****************************************************
                            if (Firebase.setInt(firebaseData, UploadOK, c)) 
                            {
                              Serial.println("Set Int Firebase OK");
                            }else{
                            //Failed?, get the error reason
                            Serial.print("Error in setInt, ");    
                            }
                        //****************************************************
                            Jsonconf = String(UrlBase); //upload confirmation
                            Jsonconf.concat(Profile);
                            Jsonconf.concat("/conf.php?s=");
                            Jsonconf.concat(k); 
                        
                            httpClient.begin(client, Jsonconf); 
                            int  httpcode = httpClient.GET();
                            if (httpcode <= 0) {
                            Serial.printf("HTTP error: %s\n", 
                            httpClient.errorToString(httpcode).c_str());
                            }
                            // Read the response.
                            String payload = httpClient.getString();
                            //Serial.print("Response HTTP = ");
                            //Serial.println(payload);
                        //***********************************************************/ 
                       }                       
        } 
        else {
          
                        if (flagOn[k] == 1){ //somente se estiver ligado, desligue   
                        //pinMode(k, OUTPUT); //definir como saída, pois existem pinos de entrada com pull-up(1)
                        digitalWrite(k, LOW);  
                        Serial.printf("Pin Off: %lu\n", k);
                        flagOn[k]=0;
                         //****************************************************
                            if (Firebase.setInt(firebaseData, UploadOK, c)) 
                            {
                              Serial.println("Set Int Firebase OK");
                            }else{
                            //Failed?, get the error reason
                            Serial.print("Error in setInt, ");    
                            }
                        //****************************************************
                            Jsonconf = String(UrlBase); //upload confirmation
                            Jsonconf.concat(Profile);
                            Jsonconf.concat("/conf.php?s=");
                            Jsonconf.concat(k); 
                        
                            httpClient.begin(client, Jsonconf); 
                            int  httpcode = httpClient.GET();
                            if (httpcode <= 0) {
                            Serial.printf("HTTP error: %s\n", 
                            httpClient.errorToString(httpcode).c_str());
                            }
                            // Read the response.
                            String payload = httpClient.getString();
                            //Serial.print("Response HTTP = ");
                            //Serial.println(payload);
                        //***********************************************************/ 
                        
                       }
        }
    }
    
  delay(1000);

}
