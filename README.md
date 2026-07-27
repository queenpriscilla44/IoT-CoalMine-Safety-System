# IoT-Based Coal Mine Safety System

## 📌 Objective
To design and implement a real-time coal mine monitoring system using IoT sensors for detecting hazardous conditions such as methane gas leaks, high temperature, humidity, and motion instability.

## ⚙️ Components Used
- ESP8266 Wi-Fi Module
- Arduino UNO
- DHT11 (Temperature & Humidity)
- MQ4 (Methane Gas Sensor)
- MPU6050 (Accelerometer & Gyroscope)
- BMP280 (Pressure Sensor)
- LCD Display
- Buzzer

## 🛠️ Methodology
- Sensors collect environmental data (temperature, humidity, gas, pressure, motion).
- Data transmitted via ESP8266 Wi-Fi and LoRa protocol.
- LCD displays local readings; buzzer triggers on unsafe conditions.
- Data logged to cloud (ThingSpeak) for remote monitoring.

## 📊 Results
- Triggered alarms when thresholds exceeded:
  - Temperature > 37°C
  - Humidity > 80%
  - Pressure > 1018 hPa
  - Gas > 40 ppm
  - Acceleration magnitude > 4 m/s²
- Graphs generated on ThingSpeak for visualization.

## 🚀 Future Scope
- AI-based prediction models for hazard detection.
- Integration with ventilation systems.
- Expansion to LoRa/Wi-Fi for long-range communication.

## 👩‍💻 Contributors
- Priscilla Queen S E  
- A. Hansley Joseph  
- Sk. Aslam Basha  
- Indugubilli Ephraim  
- Rashika Sreya Kumar  
- Gatta Manogna  

## 📎 References
- [Arduino IDE](https://www.arduino.cc/en/software)  
- [IoT Coal Mine Safety Paper](https://www.ijert.org/iot-based-coal-mine-safety-monitoring-and-alerting-system)

## 🔧 Circuit Diagram
[Circuit Diagram](media/components.png.png)

## 📊 ThingSpeak Graph
[ThingSpeak Graph](media/graph.png.png)

## 🔌 Connections
[Connections](media/connection.png)
