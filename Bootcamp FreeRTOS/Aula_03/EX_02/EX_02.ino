#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/semphr.h"

SemaphoreHandle_t xSemaphore = NULL;
TaskHandle_t Task1;
TaskHandle_t Task2;

void Task1code( void * pvParameters ) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());
  int deleteTask = 0;

  for (;;) {
    Serial.println("Task1");
    printf("Message Sent! [%d] \n", xTaskGetTickCount());
    xSemaphoreGive(xSemaphore);
    vTaskDelay(1000/ portTICK_RATE_MS);
    
    vTaskDelay(100);
  }
}
void Task2code( void * pvParameters ) {
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    Serial.println("Task2");
    if(xSemaphoreTake(xSemaphore, portMAX_DELAY))
   {
    printf("Received Message [%d] \n", xTaskGetTickCount());
   }
    
    vTaskDelay(100);
  }
}
void setup() {
 
  Serial.begin(112500);
  delay(1000);
  xSemaphore = xSemaphoreCreateBinary();
  xTaskCreatePinnedToCore(
    Task1code, /* Function to implement the task */
    "Task1", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    1,  /* Priority of the task */
    &Task1,  /* Task handle. */
    0); /* Core where the task should run */
  xTaskCreatePinnedToCore(
    Task2code, /* Function to implement the task */
    "Task2", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    1,  /* Priority of the task */
    &Task2,  /* Task handle. */
    0); /* Core where the task should run */
    
}
 
void loop() {
  delay(1000);
}
