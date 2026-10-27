#define BLYNK_TEMPLATE_ID "TMPL3kPkZeN4-"   
#define BLYNK_TEMPLATE_NAME "sensing LGD"
#define BLYNK_AUTH_TOKEN "tHMZDcGJ0rPZPYmcHDAUrcqdgnlozm4T"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

char ssid[] = "electronics";
char pass[] = "electronics";

// RX = GPIO12, TX = GPIO14
SoftwareSerial arduinoSerial(12, 14);

BlynkTimer timer;

void readSensorData()
{
  if (arduinoSerial.available())
  {
    String data = arduinoSerial.readStringUntil('\n');
    data.trim();

    int temperature;
    int humidity;
    int gasValue;
    int ldrValue;

    int result = sscanf(
      data.c_str(),
      "%d,%d,%d,%d",
      &temperature,
      &humidity,
      &gasValue,
      &ldrValue
    );

    if (result == 4)
    {
      Serial.println(data);

      Blynk.virtualWrite(V0, temperature);
      Blynk.virtualWrite(V1, humidity);
      Blynk.virtualWrite(V2, gasValue);
      Blynk.virtualWrite(V3, ldrValue);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  arduinoSerial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Connected to Blynk");

  timer.setInterval(100L, readSensorData);
}

void loop()
{
  Blynk.run();
  timer.run();
}