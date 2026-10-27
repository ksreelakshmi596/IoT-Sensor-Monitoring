#include <SoftwareSerial.h>
#include <DHT11.h>

SoftwareSerial esp(8, 9);  // RX, TX

#define DHT_PIN 4
#define MQ2_PIN A0
#define LDR_PIN A1

DHT11 dht11(DHT_PIN);

void setup()
{
  Serial.begin(9600);
  esp.begin(9600);

  Serial.println("Arduino Sensor Monitoring");
}

void loop()
{
  int temperature = 0;
  int humidity = 0;

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  int gasValue = analogRead(MQ2_PIN);
  int ldrValue = analogRead(LDR_PIN);

  if (result == 0)
  {
    // Send data to ESP8266
    esp.print(temperature);
    esp.print(",");

    esp.print(humidity);
    esp.print(",");

    esp.print(gasValue);
    esp.print(",");

    esp.println(ldrValue);

    // Display values in Serial Monitor
    Serial.print("Temperature: ");
    Serial.println(temperature);

    Serial.print("Humidity: ");
    Serial.println(humidity);

    Serial.print("MQ2 Gas: ");
    Serial.println(gasValue);

    Serial.print("LDR: ");
    Serial.println(ldrValue);
  }
  else
  {
    Serial.println("DHT11 reading failed");
  }

  delay(2000);
}