#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_task_wdt.h"
#define LED 2
int valor = 1;
/*
  Variaveis para armazenar o handle das tasks
*/
TaskHandle_t Task1;
TaskHandle_t Task2;
SemaphoreHandle_t xSemaphore;

//Prototipos das tarefas
void Task1code( void * pvParameters );

void enviaInformacao(int i) {
  Serial.println("Enviando informacao da task " + String(i));      
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);
  xSemaphore = xSemaphoreCreateMutex();//contagem inicial = 0 e contagem final = 255
  if (xSemaphore == NULL) {
    Serial.println("Não foi possível criar o semaforo");
  }
  xTaskCreatePinnedToCore(
    Task1code, /* Function to implement the task */
    "Task1", /* Name of the task */
    10000,  /* Stack size in words */
    (void*)1,  /* Task input parameter */
    2,  /* Priority of the task */
    &Task1,  /* Task handle. */
    0); /* Core where the task should run */

  xTaskCreatePinnedToCore(
    Task2code, /* Function to implement the task */
    "Task2", /* Name of the task */
    10000,  /* Stack size in words */
    (void*)1,  /* Task input parameter */
    1,  /* Priority of the task */
    &Task2,  /* Task handle. */
    0); /* Core where the task should run */
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  vTaskDelay(100);
  digitalWrite(LED, LOW);
  vTaskDelay(1000);
  xSemaphoreGive(xSemaphore);

}


void Task1code( void * pvParameters ) {

  Serial.print("Task1 running on core ");
  for (;;) {
    xSemaphoreTake(xSemaphore, portMAX_DELAY); //Pegou o semaforo
    enviaInformacao(1);
    vTaskDelay(1000);
    xSemaphoreGive(xSemaphore);//Libera o semaphoro
    vTaskDelay(10);
  }
}

void Task2code( void * pvParameters ) {

  Serial.print("Task2 running on core ");
  UBaseType_t x;
  for (;;) {
    xSemaphoreTake(xSemaphore, portMAX_DELAY); //Pegou o semaforo
    enviaInformacao(2);
    vTaskDelay(1000);
    xSemaphoreGive(xSemaphore);//Libera o semaphoro
    vTaskDelay(10);
  }
}
