#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 5        // Pin where the DHT sensor is connected
#define DHTTYPE DHT11   // Type of DHT sensor (DHT11 or DHT22)

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "xxxxxxxxxxx";
const char* password = "xxxxxx";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  dht.begin();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    float humidity = dht.readHumidity(); // Read humidity from DHT sensor
    if (isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      delay(2000);
      return;
    }
  Serial.println("Humidity: ");
  Serial.print(humidity);
    HTTPClient http;
    // go to firewall -> advanced settings-> income -> add rule -> set 8080 as trusted port -> save & exit
    http.begin("http://192.168.xx.xx:8080/"); /// localhost ip, go cmd IPCONFIG and find yours. 
    http.addHeader("Content-Type", "application/json");
    String jsonData = "{\"humidity\": " + String(humidity) + "}";
    int httpResponseCode = http.POST(jsonData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
  }
  delay(3000); // Send data every 3 seconds, adjust as needed

}





