// Name: Mark Katigbak
// Temp and Humidity sensor

#include <dht_nonblocking.h>
// Define sensor type as DHT11
#define DHT_SENSOR_TYPE DHT_TYPE_11

// Pin for the DHT sensor
static const int DHT_SENSOR_PIN = 2;
// Create DHT sensor object
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// Pin for red LED
int redLED = 4;
// Pin for blue LED
int blueLED = 5;

// Function prototype for environment measurement
static bool measure_environment(float *temperature, float *humidity);

void setup() {
  // Initialize serial communication
  Serial.begin( 9600);

  // Wait for sensor to initialize
  delay(500);

  // Print start message
  Serial.println("\nTemperature and Humidity sensor\n");

  // Set red and blue LED pin as output
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  // Variable to store temperature
  float temperature;
  // Variable to store humidity
  float humidity;

  // Measure environment and check if successful
  if(measure_environment(&temperature, &humidity) == true) {
    // Print temperature
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.println(" Degrees Celsius");

    // Print humidity
    Serial.print("Humidity: ");
    Serial.print(humidity, 1);
    Serial.println("%\n");

    // Control red LED based on temperature
    if(temperature >= 23) {
      // Turn on red LED if temp >= 23°C
      digitalWrite(redLED, HIGH);
    }
    else {
      // Turn off red LED if temp < 23°C
      digitalWrite(redLED, LOW);
    }

    // Control blue LED based on humidity
    if(humidity >= 28) {
      // Turn on blue LED if humidity is >= 28%
      digitalWrite(blueLED, HIGH);
    }
    else {
      // Turn off blue LED if humidity < 28%
      digitalWrite(blueLED, LOW);
    }
  }
}

static bool measure_environment(float *temperature, float *humidity) {
  // Timestamp for last measurement
  static unsigned long measurement_timestamp = millis();

  // Measure every 3 seconds
  if(millis() - measurement_timestamp > 3000ul)
  {
    // Attempt to get temperature and humidity
    if(dht_sensor.measure(temperature, humidity) == true )
    {
      // Update timestamp after successful measurement
      measurement_timestamp = millis();
      // Return true if measurement is successful
      return(true);
    }
  }

  // Return false if measurement failed or not time yet
  return(false);
}
