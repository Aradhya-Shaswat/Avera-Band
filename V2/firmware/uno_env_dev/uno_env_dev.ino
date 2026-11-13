#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

#define SAMPLE_INTERVAL 2000UL

DHT dht(DHT_PIN, DHT_TYPE);

uint32_t sequenceNumber = 0;
uint32_t lastSample = 0;

const char DEVICE_NAME[] = "AVERA-UNO-DEV";

void sendHello() {
    Serial.println(
        F("{\"v\":1,"
          "\"type\":\"hello\","
          "\"device\":\"AVERA-UNO-DEV\","
          "\"firmware\":\"0.1.0\"}")
    );
}

void sendTemperature(float temperature) {

    sequenceNumber++;

    Serial.print(F("{\"v\":1,"));
    Serial.print(F("\"type\":\"telemetry\","));

    Serial.print(F("\"device\":\""));
    Serial.print(DEVICE_NAME);
    Serial.print(F("\","));

    Serial.print(F("\"seq\":"));
    Serial.print(sequenceNumber);
    Serial.print(F(","));

    Serial.print(F("\"uptime_ms\":"));
    Serial.print(millis());
    Serial.print(F(","));

    Serial.print(F("\"sensors\":{"));
    Serial.print(F("\"ambient_temperature_c\":"));
    Serial.print(temperature, 1);
    Serial.println(F("}}"));
}

void sendSensorError() {

    Serial.print(
        F("{\"v\":1,"
          "\"type\":\"sensor_error\","
          "\"device\":\"AVERA-UNO-DEV\","
          "\"sensor\":\"DHT11\","
          "\"code\":\"READ_FAILED\","
          "\"uptime_ms\":")
    );

    Serial.print(millis());
    Serial.println(F("}"));
}

void setup() {

    Serial.begin(115200);

    dht.begin();

    delay(2000);

    sendHello();
}

void loop() {

    uint32_t now = millis();

    if (now - lastSample >= SAMPLE_INTERVAL) {

        lastSample = now;

        float temperature = dht.readTemperature();

        if (isnan(temperature)) {
            sendSensorError();
        } else {
            sendTemperature(temperature);
        }
    }
}

