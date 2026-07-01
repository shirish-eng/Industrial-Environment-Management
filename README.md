# Edge-to-Cloud Industrial Environment Management

An IoT-based industrial monitoring system that collects real-time temperature and gas data using the **LPC2148 (ARM7TDMI-S)** microcontroller and uploads it to the **ThingSpeak** cloud platform through the **ESP-01 (ESP8266)** Wi-Fi module.

## Features

* Real-time temperature monitoring using LM35
* Harmful gas detection using MQ-2
* Edge-based data processing
* UART communication with ESP-01 using AT commands
* Cloud data visualization using ThingSpeak
* Local display on a 16×2 LCD

## Hardware

* LPC2148 (ARM7TDMI-S)
* LM35 Temperature Sensor
* MQ-2 Gas Sensor
* ESP-01 (ESP8266)
* 16×2 LCD

## Software

* Embedded C
* Keil µVision 4
* Flash Magic
* Proteus

## System Flow

```text
LM35 + MQ-2 → LPC2148 → UART → ESP-01 → Wi-Fi → ThingSpeak
```

## Repository Structure

```text
Source_Code/
Keil_Project/
Proteus_Simulation/
Images/
```

## Future Enhancements

* MQTT integration
* Mobile application support
* Multi-sensor monitoring
* Alert notification system

## Author

**Shirish**
ECE Graduate (2024) | Embedded Systems Enthusiast
