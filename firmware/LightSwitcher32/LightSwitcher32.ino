#include <ESP32Servo.h>
#include "esp_sleep.h"
#include "driver/gpio.h"

Servo myServo;

const gpio_num_t input = GPIO_NUM_2;

void setup() {
  pinMode(input, INPUT);

  int currentState = digitalRead(input);

  myServo.attach(6);

  if (currentState == HIGH) {
    myServo.write(125);
  } else {
    myServo.write(45);
  }

  delay(1500);
  myServo.detach();

  if (currentState == HIGH) {
    gpio_wakeup_enable(input, GPIO_INTR_LOW_LEVEL);
  } else {
    gpio_wakeup_enable(input, GPIO_INTR_HIGH_LEVEL);
  }

  esp_deep_sleep_enable_gpio_wakeup(
    1ULL << input,
    currentState == HIGH
    ? ESP_GPIO_WAKEUP_GPIO_LOW
    : ESP_GPIO_WAKEUP_GPIO_HIGH
  );

  esp_deep_sleep_start();
}

void loop() {
}
