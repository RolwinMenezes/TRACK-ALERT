#include <Arduino.h>
#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 14
#define BUZZER_PIN 6
#define VIBRATION_SENSOR_PIN 9

#define THRESHOLD_DISTANCE 20

NewPing sonar(TRIGGER_PIN, ECHO_PIN);

bool triggered = false;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
}

void loop() {
  int vibrationValue = digitalRead(VIBRATION_SENSOR_PIN);

  if (vibrationValue == HIGH) {
    triggered = true;
  }

  if (triggered) {
    int distance = sonar.ping_cm();

    if (distance < THRESHOLD_DISTANCE) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1000); 
      digitalWrite(BUZZER_PIN, LOW);
      
      triggered = false;
    }
  }

  delay(100);
}
