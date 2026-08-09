# 🏙️ Smart Public Facility Locator System

A GPS and IoT-based **Smart Public Facility Locator System** designed to help users quickly find nearby public facilities such as hospitals, police stations, fire stations, pharmacies, ATMs, bus stops, parking areas, and other essential services.

The system uses an **ESP32**, **GPS module**, **OLED display**, **Wi-Fi connectivity**, and an online facility database/API to provide location-based public service information.

---

## 📌 Project Overview

Finding essential public facilities during normal situations or emergencies can be difficult and time-consuming. This project provides a smart and user-friendly solution for locating nearby public facilities based on the user's current GPS location.

The ESP32 obtains the user's location through a GPS module and connects to the internet using Wi-Fi. The system can then retrieve nearby facility information from an online database/API and display the information to the user.

---

## 🎯 Objectives

* To identify the user's current location using GPS.
* To locate nearby public facilities.
* To display facility information on an OLED display.
* To provide emergency assistance using an SOS button.
* To provide audible and visual emergency alerts.
* To connect the system to an online database/API.
* To improve accessibility to essential public services.
* To support future smart-city applications.

---

## ✨ Features

### 📍 GPS Location Detection

The system obtains the user's current latitude and longitude using the NEO-6M GPS module.

### 🔎 Facility Search

Users can search for nearby hospitals, police stations, fire stations, pharmacies, ATMs, bus stops, and other public facilities.

### 🗺️ Location-Based Services

The system uses the user's geographical coordinates to identify facilities near the current location.

### 📺 OLED Display

An OLED display provides information such as GPS coordinates, system status, and nearby facility details.

### 📡 Wi-Fi Connectivity

The ESP32 connects to the internet through Wi-Fi to communicate with the online server or facility database.

### 🚨 Emergency SOS

An SOS button activates emergency mode and provides an alert using the buzzer and red LED.

### 🔊 Buzzer Alert

The buzzer produces an audible notification when an emergency condition is activated.

### 💡 Status Indicators

Green and red LEDs indicate normal system operation and emergency status.

### ☁️ Cloud/API Integration

The system can be connected to a cloud database or location API for retrieving facility information.

---

## 🧰 Hardware Components

| Component               |    Quantity | Purpose             |
| ----------------------- | ----------: | ------------------- |
| ESP32 Development Board |           1 | Main controller     |
| NEO-6M GPS Module       |           1 | Location detection  |
| 0.96" OLED I2C Display  |           1 | Display information |
| Push Button             |           2 | Search and SOS      |
| Active Buzzer           |           1 | Emergency alert     |
| Green LED               |           1 | Normal status       |
| Red LED                 |           1 | Emergency status    |
| 220Ω Resistor           |           2 | LED protection      |
| Breadboard              |           1 | Circuit assembly    |
| Jumper Wires            | As required | Connections         |
| USB Cable               |           1 | Programming/power   |
| 5V Power Bank           |           1 | Portable power      |

---

## 🔌 Circuit Connections

### GPS Module → ESP32

| GPS Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 3.3V      |
| GND     | GND       |
| TX      | GPIO16    |
| RX      | GPIO17    |

### OLED → ESP32

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO21    |
| SCL      | GPIO22    |

### Search Button

| Button         | ESP32  |
| -------------- | ------ |
| Signal         | GPIO18 |
| Other terminal | GND    |

### SOS Button

| Button         | ESP32  |
| -------------- | ------ |
| Signal         | GPIO19 |
| Other terminal | GND    |

### Buzzer

| Buzzer   | ESP32  |
| -------- | ------ |
| Positive | GPIO23 |
| Negative | GND    |

### Green LED

| LED     | ESP32               |
| ------- | ------------------- |
| Anode   | GPIO25 through 220Ω |
| Cathode | GND                 |

### Red LED

| LED     | ESP32               |
| ------- | ------------------- |
| Anode   | GPIO26 through 220Ω |
| Cathode | GND                 |

---

## 🏗️ System Architecture

```text
                    +------------------+
                    |      GPS         |
                    |     NEO-6M       |
                    +--------+---------+
                             |
                             |
                             v
                    +------------------+
                    |      ESP32       |
                    | Main Controller  |
                    +--------+---------+
                             |
              +--------------+--------------+
              |              |              |
              v              v              v
        +-----------+   +---------+    +----------+
        |   OLED    |   | Buttons |    |  Buzzer  |
        |  Display  |   | Search  |    |   + LED  |
        +-----------+   |   SOS   |    +----------+
                        +---------+
                             |
                             v
                         Wi-Fi
                             |
                             v
                   +-------------------+
                   | Cloud / Web API   |
                   | Facility Database |
                   +---------+---------+
                             |
                             v
                   +-------------------+
                   | Nearby Facilities |
                   +-------------------+
```

---

## ⚙️ Working Principle

1. The ESP32 starts the system and initializes all connected components.
2. The GPS module receives satellite signals and obtains the user's latitude and longitude.
3. The ESP32 connects to the available Wi-Fi network.
4. When the user presses the Search button, the system sends the current location to the server/API.
5. The server searches for nearby public facilities.
6. Facility information is returned to the ESP32.
7. The OLED displays the available facility information.
8. When the SOS button is pressed, the emergency alert is activated.
9. The red LED and buzzer indicate emergency mode.
10. The system can send the user's location to an emergency server or registered contact in an advanced implementation.

---

## 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* C/C++ Arduino Programming
* TinyGPS++
* Adafruit GFX Library
* Adafruit SSD1306 Library
* WiFi Library
* HTTPClient Library

---

## 📚 Arduino Libraries

Install the following libraries using the Arduino IDE Library Manager:

```text
TinyGPS++
Adafruit GFX Library
Adafruit SSD1306
```

The following libraries are generally included with the ESP32 board package:

```text
WiFi
HTTPClient
Wire
```

---

## 📂 Project Structure

```text
Smart-Public-Facility-Locator/
│
├── README.md
│
├── Arduino/
│   └── Smart_Public_Facility_Locator.ino
│
├── Circuit/
│   └── circuit_diagram.png
│
├── Documentation/
│   ├── Project_Report.pdf
│   └── Project_Presentation.pptx
│
├── Images/
│   └── project_setup.jpg
│
└── LICENSE
```

---

## 🔑 Configuration

Open the Arduino code and enter your Wi-Fi credentials:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

If an external facility API is used, configure the required API URL and API key:

```cpp
const char* serverURL = "YOUR_SERVER_URL";
const char* apiKey = "YOUR_API_KEY";
```

**Do not upload real passwords or API keys to a public GitHub repository.**

---

## 🖥️ Example OLED Output

```text
SMART FACILITY
----------------

GPS LOCATION

Lat: 11.6643
Lng: 78.1460

WiFi: Connected
```

Example facility result:

```text
NEAREST FACILITY

Hospital
Distance: 1.2 km

Press SOS
for Emergency
```

---

## 🚨 Emergency Mode

When the SOS button is pressed:

```text
SOS BUTTON
     |
     v
ESP32
     |
     +----> RED LED ON
     |
     +----> BUZZER ON
     |
     +----> GET GPS LOCATION
     |
     +----> SEND LOCATION
```

This feature can be extended to send the emergency location to a predefined server, mobile application, or emergency contact.

---

## 🌐 Possible Facility Categories

The system can support:

```text
🏥 Hospitals
🚔 Police Stations
🔥 Fire Stations
💊 Pharmacies
🚑 Ambulance Services
🚻 Public Toilets
🚌 Bus Stops
🚉 Railway Stations
🏦 Banks
💳 ATMs
⛽ Petrol Stations
🅿️ Parking Areas
⚡ EV Charging Stations
💧 Drinking Water Points
```

---

## 🔮 Future Enhancements

* AI-based facility recommendations
* Voice-based facility search
* Mobile application
* Google Maps/OpenStreetMap integration
* Real-time traffic information
* Offline map support
* Multilingual voice assistance
* Live parking availability
* Wheelchair-accessible route detection
* Real-time facility occupancy
* GSM-based emergency SMS
* Firebase cloud database
* Web-based admin dashboard
* Smart-city IoT integration

---

## 🌆 Applications

The system can be used in:

* Smart Cities
* Tourist Locations
* Educational Campuses
* Railway Stations
* Airports
* Hospitals
* Public Transportation Areas
* Municipal Services
* Emergency Response Systems
* Large Industrial Campuses

---

## ✅ Advantages

* Easy to use
* Low-cost implementation
* GPS-based location detection
* Fast facility searching
* Emergency assistance
* Internet-based information updates
* Expandable IoT architecture
* Suitable for smart-city applications
* Can be integrated with mobile and web applications

---

## ⚠️ Limitations

* GPS accuracy depends on satellite signal quality.
* Internet connectivity is required for online facility searching.
* External map/API services may have usage limits.
* Facility information must be regularly updated.
* Emergency communication requires an appropriate backend or communication service.

---

## 👨‍💻 Technologies Used

```text
Hardware:
ESP32
NEO-6M GPS
OLED
LED
Buzzer
Push Buttons

Programming:
C/C++
Arduino IDE

Communication:
GPS
Wi-Fi
HTTP

Database/API:
Cloud Database
Location API

Future:
Firebase
Google Maps / OpenStreetMap
Mobile Application
AI
```

---

## 📊 Expected Result

The Smart Public Facility Locator System successfully detects the user's location and helps identify nearby public facilities. The system provides a simple interface for searching essential services and includes an SOS mechanism for emergency situations. The project demonstrates the integration of **IoT, GPS, wireless communication, cloud services, and embedded systems** for smart-city applications.

---

## 🎓 Project Type

**Final Year ECE / IoT / Embedded Systems Project**

**Project Name:** Smart Public Facility Locator System

**Controller:** ESP32

**Location Technology:** GPS

**Communication:** Wi-Fi

**Display:** OLED

**Programming:** Arduino C/C++

---

## 📜 License

This project is developed for educational and academic purposes. You are free to modify and improve the project according to your requirements.

---

## ⭐ Support

If you find this project useful, consider giving the repository a ⭐ on GitHub.
