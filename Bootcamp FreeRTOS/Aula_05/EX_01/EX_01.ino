#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t xTask1Handle;
TaskHandle_t xTask2Handle;

void xTask1Function(void *pvParameters);
void xTask2Function(void *pvParameters);


void xTask1Function(void *pvParameters) {
  BaseType_t xResult;
  uint32_t ulNotifiedValue = 0;
  while (1) {


    /*
      RECEBE A NOTIFICAÇÃO
      0x00 -> bits a serem limpos na entrada
      0x00 -> bits a serem limpos na saida
      ulNotifiedValue -> Valor da notificação
      portMAX_DELAY -> Tempo de espera
    */
    xResult = xTaskNotifyWait(0X00, 0x00, &ulNotifiedValue,  portMAX_DELAY);
    if (xResult == pdPASS)
    {
      printf("A task2 ja roudou %zu vezes. E eu sou a task1\n", ulNotifiedValue);
    }

  }
}
void xTask2Function(void *pvParameters) {
  int count = 0;
  while (1) {
    /*
     * ENVIA A NOTIFICAÇÃP
     * xTask1Handle -> Task receptora
     * count ->Variável enviada
     * eSetValueWithoutOverwrite -> Ação da notificação. É um tipo enum que pode ser:
     *  1. eNoAction -> A receptora recebe o dado e este não é alterado
     *  2. eSetBits -> O dado terá seus bits operado pelo operador OU (|). É uma alternativa aos event groups
     *  3. eIncrement -> O valor será incrementado em uma unidade. ulValue não é usado nesse caso
     *  4. eSetValueWithoutOverwrite -> Se a task ainda não tiver recebido notificação, a notificação receberá o valor do contador. Mas se receber notificação, o valor será prescrito. É uma alternativa ao envio de um valor para uma fila
    
    */
    xTaskNotify(xTask1Handle, count, eSetValueWithoutOverwrite);
    count++;
    Serial.println("A notificacao foi enviada da task2 para a task1");
    vTaskDelay(500);
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreate(xTask1Function, "task1", 10000, NULL, 2, &xTask1Handle);
  xTaskCreate(xTask2Function, "task2", 10000, NULL, 1, &xTask2Handle);


}

void loop() {
  // put your main code here, to run repeatedly:
  vTaskDelay(1000);

}
