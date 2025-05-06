# IoT Distance Monitoring System with ESP32 and Arduino Cloud

## 📌 Project Overview
An IoT system that:
- Measures distance using an HC-SR04 ultrasonic sensor
- Triggers a buzzer when objects come within 10cm
- Sends real-time data to Arduino Cloud
- Built with ESP32 for WiFi connectivity

## 🛠 Hardware Components
- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- Piezo Buzzer
- Breadboard & Jumper Wires
- Micro-USB Cable

## 🔌 Wiring Diagram
| ESP32 Pin | Connected To |
|-----------|-------------|
| GPIO26    | TRIG        |
| GPIO25    | ECHO        |
| GPIO17    | Buzzer (+)  |
| GND       | Buzzer (-) & Sensor GND |
| 5V        | Sensor VCC  |

## ☁ Arduino Cloud Setup
1. Create a new "Thing" in Arduino IoT Cloud
2. Add these variables:
   - `distance` (float, read-only)
   - `duration` (float, read-only)
3. Configure your WiFi credentials
4. Upload this sketch to your ESP32

## ⚙️ Functionality
- Continuously measures distance (cm)
- Activates buzzer at 2000Hz when distance < 10cm
- Serial monitor outputs distance readings
- Data syncs with Arduino Cloud dashboard

## 📋 Code Structure
```plaintext
void setup()
  - Initializes serial communication
  - Configures ultrasonic sensor pins
  - Sets up buzzer with LEDC timer
  - Connects to Arduino Cloud

void loop()
  - Updates cloud connection
  - Triggers ultrasonic pulse
  - Calculates distance
  - Controls buzzer based on threshold
  - Prints to serial monitor
```

## 📊 Sample Serial Output
- distance: 25.50 cm
- distance: 8.20 cm  [BUZZER ACTIVATED]
- distance: 15.75 cm

## 🤝 Collaborators
<a href="https://github.com/kondats99">
  <img src="https://img.shields.io/badge/kondats99-Profile-blue?style=flat&logo=github" alt="kondats99">
</a>  
<br>
<a href="https://github.com/st2berry">
  <img src="https://img.shields.io/badge/st2berry-Profile-blue?style=flat&logo=github" alt="st2berry">
</a>
