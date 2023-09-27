#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

SemaphoreHandle_t xSemaphoreCounting;

void taskIncrement(void *parameter) {
  while (1) {
    xSemaphoreGive(xSemaphoreCounting); // Incrementa o semáforo de contagem
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void taskDecrement(void *parameter) {
  while (1) {
    if (xSemaphoreTake(xSemaphoreCounting, portMAX_DELAY)) { // Tenta adquirir um token
      Serial.println("Semáforo de Contagem: Token adquirido");
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  xSemaphoreCounting = xSemaphoreCreateCounting(5, 0); // Criar um semáforo de contagem com 5 tokens

  xTaskCreate(taskIncrement, "Incremento", 1000, NULL, 1, NULL);
  xTaskCreate(taskDecrement, "Decremento", 1000, NULL, 1, NULL);

}

void loop() {
  // O loop principal não faz nada no FreeRTOS
  delay(1000);
}
