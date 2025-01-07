// Name: Mark Katigbak
// Temp and Humidity sensor

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

int redLED = 4;
int blueLED = 5;

static bool measure_environment(float *temperature, float *humidity);

void setup() {
  Serial.begin( 9600);

  delay(500);

  Serial.println("\nTemperature and Humidity sensor\n");

  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  float temperature;
  float humidity;

  if(measure_environment(&temperature, &humidity) == true) {
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.println(" Degrees Celsius");

    Serial.print("Humidity: ");
    Serial.print(humidity, 1);
    Serial.println("%\n");

    if(temperature >= 23) {
      digitalWrite(redLED, HIGH);
    }
    else {
      digitalWrite(redLED, LOW);
    }
    
    if(humidity >= 28) {
      digitalWrite(blueLED, HIGH);
    }
    else {
      digitalWrite(blueLED, LOW);
    }
  }
}

static bool measure_environment(float *temperature, float *humidity) {
  static unsigned long measurement_timestamp = millis();

  if(millis() - measurement_timestamp > 3000ul)
  {
    if(dht_sensor.measure(temperature, humidity) == true )
    {
      measurement_timestamp = millis();
      return(true);
    }
  }

  return(false);
}
