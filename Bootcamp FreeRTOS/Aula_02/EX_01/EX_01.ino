#include <freertos/queue.h>

QueueHandle_t xQueue;

void setup() {
  Serial.begin(115200);
  xQueue = xQueueCreate(10, sizeof(int));

  xTaskCreate(task1, "Tarefa 1", 10000, NULL, 1, NULL);
  xTaskCreate(task2, "Tarefa 2", 10000, NULL, 1, NULL);
}

void loop() {
  // O loop principal não faz nada no FreeRTOS
  delay(1000);
}


void task1( void * parameter ) {
  int data = 0;
  for(;;) {
    Serial.print("Dado enviado: ");
    Serial.println(data);
    xQueueSend(xQueue, &data, portMAX_DELAY);
    data++;
    if(data == 10)
    {
      data = 0;
    }
    vTaskDelay(1000);
  }
    Serial.println("Ending task 1");
    vTaskDelete( NULL );
}

void task2( void * parameter ) {
  int receivedData;
  for(;;) {
    /*
    * portMAX_DELAY: A tabela é bloqueada aaguardando a fila ser liberada para uso
    * (TickType_t)1000 -> 1 segundo aguardando...se a fila não for liberada, passe para a próxima instrução
    */
    xQueueReceive(xQueue, &receivedData, (TickType_t)100);
    Serial.print("Dados recebidos: ");
    Serial.println(receivedData);
    vTaskDelay(100);
  }
    Serial.println("Ending task 2");
    vTaskDelete( NULL );
}
