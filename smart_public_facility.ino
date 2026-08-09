#include <WiFi.h>
#include <HTTPClient.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

TinyGPSPlus gps;

HardwareSerial GPS(2);

// WiFi
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Pins
#define SEARCH_BUTTON 18
#define SOS_BUTTON 19
#define BUZZER 23
#define GREEN_LED 25
#define RED_LED 26

String facilityName = "";
String distance = "";

void setup()
{
  Serial.begin(115200);

  GPS.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(SEARCH_BUTTON, INPUT_PULLUP);
  pinMode(SOS_BUTTON, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(BUZZER, LOW);

  Wire.begin(21,22);

  display.begin(SSD1306_SWITCHCAPVCC,0x3C);

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.println("Smart Public");
  display.println("Facility Locator");
  display.display();

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED)
  {
      delay(500);
      Serial.print(".");
  }

  digitalWrite(GREEN_LED,HIGH);

  display.clearDisplay();
  display.println("WiFi Connected");
  display.display();

  delay(2000);
}

void loop()
{

 while(GPS.available())
 {
    gps.encode(GPS.read());
 }

 if(gps.location.isUpdated())
 {

    double latitude = gps.location.lat();
    double longitude = gps.location.lng();

    Serial.print("Latitude : ");
    Serial.println(latitude);

    Serial.print("Longitude : ");
    Serial.println(longitude);

    display.clearDisplay();

    display.setCursor(0,0);

    display.print("Lat:");
    display.println(latitude,6);

    display.print("Lng:");
    display.println(longitude,6);

    display.display();
 }

 if(digitalRead(SEARCH_BUTTON)==LOW)
 {
      searchFacility();
 }

 if(digitalRead(SOS_BUTTON)==LOW)
 {
      emergencyAlert();
 }

}