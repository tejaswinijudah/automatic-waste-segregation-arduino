# Automatic Waste Segregation Mechanism Using Arduino Uno

This project implements an embedded system for automatic waste segregation using Arduino Uno.
The system classifies waste into metallic, wet/organic, and dry categories using sensor-based decision logic.

## Components Used
- Arduino Uno
- IR Sensor (Object Detection)
- Metal Detection Sensor (NPN type)
- Moisture Sensor
- Servo Motor

## Working Principle
1. The IR sensor detects the presence of waste.
2. The metal sensor identifies metallic waste.
3. The moisture sensor differentiates wet and dry waste.
4. Based on sensor inputs, the servo motor rotates to direct waste into the appropriate bin.

## Waste Classification Logic
- Metal Waste → Servo at 0°
- Dry Waste → Servo at 90°
- Wet / Organic Waste → Servo at 180°

## Tools & Technologies
- Arduino IDE
- Embedded C / Arduino Programming
- Servo Control and Sensor Interfacing

## Project Report
📄 `report/Automatic_Waste_Segregation_Report.pdf`
