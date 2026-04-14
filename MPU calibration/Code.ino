#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 mpu;

void setup() {
  Wire.begin();
  // Set serial monitor to 115200 for faster printing
  Serial.begin(115200); 

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("ERROR: MPU6050 connection failed!");
    while (1); // Halt if sensor isn't found
  }
  Serial.println("MPU6050 connection successful.");

  // CRITICAL: The sensor must be perfectly horizontal and motionless
  Serial.println("Keep your robot PERFECTLY STILL and FLAT.");
  Serial.println("Calibrating in 3 seconds...");
  delay(3000);

  // Clear any old offsets to start fresh
  mpu.setXAccelOffset(0);
  mpu.setYAccelOffset(0);
  mpu.setZAccelOffset(0);
  mpu.setXGyroOffset(0);
  mpu.setYGyroOffset(0);
  mpu.setZGyroOffset(0);

  // Internal PID calibration
  Serial.println("Calibrating Gyroscope...");
  mpu.CalibrateGyro(6); // number of tuning iterations
  
  Serial.println("Calibrating Accelerometer...");
  mpu.CalibrateAccel(6);

  Serial.println("\n--- FINAL OFFSETS ---");
  mpu.PrintActiveOffsets();
  
  Serial.println("\nCopy these values into the setup() of your main robot code!");
}

void loop() {
  // Calibration is done in setup(), nothing needed here.
}
