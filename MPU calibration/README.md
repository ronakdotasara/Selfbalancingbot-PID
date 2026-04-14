# MPU6050 Calibration Module

Lightweight calibration utility for extracting raw accelerometer and gyroscope offsets from the MPU6050 IMU prior to control system implementation.

Designed for robotics platforms requiring reliable state estimation and sensor bias correction.

---

## Overview

This module initializes the MPU6050 over I2C, verifies communication integrity, and retrieves the current accelerometer and gyroscope offset values.

These offsets are essential for reducing drift and improving measurement accuracy in dynamic systems.

---

## Technical Stack

- Arduino (Uno / Nano / compatible boards)  
- I2C communication (Wire library)  
- MPU6050 IMU  

Baud rate: **115200**

---

## Workflow

1. Upload the calibration sketch to your Arduino.
2. Open the Serial Monitor at 115200 baud.
3. Record the printed gyro and accelerometer offsets.
4. Apply these values in your main control firmware.

---

## System Context

This calibration step is typically performed before implementing:

- PID control  
- State-space control  
- Complementary or Kalman filtering  
- Self-balancing robot architectures  
- Inverted pendulum systems  

Accurate sensing → Stable estimation → Reliable control.

---

## Hardware Connections (I2C)

- VCC → 5V / 3.3V (depending on module)  
- GND → GND  
- SDA → SDA  
- SCL → SCL  

---

## License

MIT License
