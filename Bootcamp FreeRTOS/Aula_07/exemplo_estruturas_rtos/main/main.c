#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/queue.h"
#include "freertos/semphr.h"

TaskHandle_t myTaskHandle = NULL;
TaskHandle_t myTaskHandle2 = NULL;
TaskHandle_t myTaskHandle3 = NULL;
TaskHandle_t myTaskHandle4 = NULL;
TaskHandle_t myTaskHandle5 = NULL;
TaskHandle_t myTaskHandle6 = NULL;

QueueHandle_t queue;
SemaphoreHandle_t xSemaphore = NULL;

void Demo_Task5(void *arg)
{
    while(1){
        printf("Message Sent by semaphore! \n");
        xSemaphoreGive(xSemaphore);
        vTaskDelay(1000);
    }
}

void Demo_Task6(void *arg)
{
    while(1){
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY))
        {
        printf("Received Message by semaphore\n");
        }
        vTaskDelay(100);
    }
}

/**
 * @brief Task criada para enviar 3 dados a uma fila chamada "queue"
 * 
 * @param arg 
 */
void Demo_Task3(void *arg)
{
    char txBuffer[50];
    queue = xQueueCreate(5, sizeof(txBuffer)); 
    if (queue == 0)
    {
     printf("Failed to create queue= %p\n", queue);
    }

    sprintf(txBuffer, "Hello from Demo_Task 3");
    xQueueSend(queue, (void*)txBuffer, (TickType_t)0);

    sprintf(txBuffer, "Hello from Demo_Task 4");
    xQueueSend(queue, (void*)txBuffer, (TickType_t)0); 

    sprintf(txBuffer, "Hello from Demo_Task 5");
    xQueueSend(queue, (void*)txBuffer, (TickType_t)0);  

    while(1){
        vTaskDelay(1000);
    }
}

/**
 * @brief Task criada para receber dados de uma fila chamada "queue"
 * 
 * @param arg 
 */
void Demo_Task4(void *arg)
{
    char rxBuffer[50];
    while(1){
     if( xQueueReceive(queue, &(rxBuffer), (TickType_t)5))
     {
      printf("Received data from queue == %s\n", rxBuffer);
      vTaskDelay(1000);

     }
    }
}

/**
 * @brief Task criada para aumentar o aprendizado sobre tasks
 * 
 * @param arg 
 */
void Demo_Task(void *arg)
{
    for(;;){
        printf("Demo_Task 1 printing..\n");
        vTaskDelay(100);
    }
}

/**
 * @brief Task criada para aumentar o aprendizado sobre tasks
 * 
 * @param arg 
 */
void Demo_Task2(void *arg)
{
    for(;;){
        printf("Demo_Task2 printing..\n");
        vTaskDelay(1000);
    }
}

void app_main(void)
{
    /**
     * @brief Declaração das tasks
     * 
     */
   xTaskCreate(Demo_Task, "Demo_Task", (1*1024), NULL, 2, &myTaskHandle);
   xTaskCreatePinnedToCore(Demo_Task2, "Demo_Task2", (1*1024), NULL,10, &myTaskHandle2, 1);
   xTaskCreate(Demo_Task3, "Demo_Task3", (1*1024), NULL, 10, &myTaskHandle3);
   xTaskCreatePinnedToCore(Demo_Task4, "Demo_Task4", (2*1024), NULL,10, &myTaskHandle4, 1);

    //Semáforo
   xSemaphore = xSemaphoreCreateBinary();
   xTaskCreate(Demo_Task5, "Demo_Task5", (1*1024), NULL, 10, &myTaskHandle5);
   xTaskCreatePinnedToCore(Demo_Task6, "Demo_Task6", (1*1024), NULL,10, &myTaskHandle6, 1);

 }