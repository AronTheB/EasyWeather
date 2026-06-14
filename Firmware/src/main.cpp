#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <WiFi.h>
#include <Adafruit_SSD1306.h>

#define SEALEVELPRESSURE_HPA (1013.25)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme; // I2C

const char* ssid = "123";
const char* password = "123";
WiFiServer server(80);

unsigned long delayTime;

void setup() {
    Serial.begin(9600);
    Serial.println(F("BME280 test"));

    if (! bme.begin(0x77, &Wire)) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Could not find SSD1306!");
        while (1);
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Connecting WiFi...");
    display.display();

    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("WiFi connected!");
    display.setCursor(0, 10);
    display.print(WiFi.localIP());
    display.display();
    delay(2000);

    server.begin();
    delayTime = 5000;
}

void loop() {
    bme.takeForcedMeasurement();
    
    printValues();
    delay(delayTime);
}

// Add webserver later
void printValues() {
    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();
    float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
    float pressure = bme.readPressure() / 100.0F;

    Serial.printf("Temp: %.1f C | Pressure: %.1f hPa | Alt: %.1f m | Hum: %.1f%%\n",temperature, pressure, altitude, humidity);

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.printf("Temp: %.1f C\n", temperature);

    display.setCursor(0, 16);
    display.printf("Pressure: %.1f hPa\n", pressure);

    display.setCursor(0, 32);
    display.printf("Humidity: %.1f%%\n", humidity);

    display.setCursor(0, 48);
    display.printf("Altitude: %.1f m\n", altitude);
    
    display.display();

    

}