# AULA 02 - Bootcamp ESP 32 Free RTOS

Aula 02 sobre programação FreeRTOS usando ESP 32 e Arduino IDE.

## Filas

São estruturas de dados tipo FiFo capazes de permitir o transito de dados entre tasks.

## Criando Filas

QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize);

 - uxQueueLength: numero de elementos que a fila irá conter.
 - uxItemSize: tamanho em byte de cada elemento da fila.

## Inserindo dados na Fila

BaseType_t xQueueSend(QueueHandle_t xQueue, 
const void * pvItemToQueue, 
TickType_t xTicksToWait);

 - xQueue: variável do tipo QueueHandle_t com o identificador da fila.
 - pvItemToQueue: ponteiro do conteúdo a ser postado na fila.
 - xTicksToWait: tempo máximo que a tarefa deve bloquear esperando que haja espaço disponível na fila, caso a queue esteja cheia.

## Removendo dados na Fila

BaseType_t xQueueReceive( QueueHandle_t xQueue, 
void *pvBuffer, 
TickType_t xTicksToWait);

 - xQueue: variável do tipo QueueHandle_t com o identificador da fila.
 - pvBuffer: ponteiro para o buffer no qual o elemento da fila será copiado.
 - xTicksToWait: tempo máximo que a tarefa deve permanecer bloqueada à espera de um elemento na fila, caso a fila esteja vazia.
   Se esse parâmetro for definido com o valor 0, faz com que a tarefa retorne imediatamente se a fila estiver vazia.

## Deletando a Fila

void vQueueDelete( QueueHandle_t xQueue );