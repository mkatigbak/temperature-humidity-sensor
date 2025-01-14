# Temperature and Humidity Sensor

## Overview
This program reads temperature and humidity data from a DHT11 sensor and uses the data to control two LEDs (red and blue) based on certain conditions. It also prints the temperature and humidity readings to the Serial Monitor.

## Components
* DHT11 sensor: Measures temperature and humidity.
* Red LED: Turns on when the temperature is 23°C or higher.
* Blue LED: Turns on when the humidity is 28% or higher.

## Pin Configuration
* DHT11 Sensor: Connected to pin 2.
* Red LED: Connected to pin 4.
* Blue LED: Connected to pin 5.

## Key Functions
```setup()```
* Initializes the serial communication and the LEDs.
* Waits for the sensor to initialize and then prints a start message.

```loop()```
* Reads temperature and humidity from the sensor.
* Prints the temperature and humidity values to the Serial Monitor.
* Controls the red LED based on the temperature and the blue LED based on the humidity.

```measure_environment()```
* Measures the temperature and humidity every 3 seconds.
* Returns ```true``` if the measurement is successful, ```false``` if not.

## Logic
* Red LED: Lights up if the temperature is greater than or equal to 23°C.
* Blue LED: Lights up if the humidity is greater than or equal to 28%.

## How to Use
1. Connect the DHT11 sensor to the Arduino as per the pin configuration.
2. Upload the code to the Arduino.
3. Open the Serial Monitor to view the temperature and humidity readings.
4. Observe the LEDs: the red LED lights up for high temperatures, and the blue LED lights up for high humidity.

## Requirements
* DHT11 sensor library: ```dht_nonblocking``` library needs to be installed in the Arduino IDE.
