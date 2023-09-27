# AULA 01 - Bootcamp ESP 32 Free RTOS

Aula 01 sobre programação FreeRTOS usando ESP 32 e Arduino IDE.

## FreeRTOS

FreeRTOS é um Kernel de sistema operacional de tempo real comprado e mantido pela Amazon.

## Escalonador

Escalonador corresponde ao algoritmo responsável pelo gerenciamento dos processos a serem executados pela CPU. Responsável pelo gerenciamento da próxima tarefa a ser executada pela CPU.

## Kernel

Corresponde ao Núcleo do sistema operacional. Gerencia a execução dos processos seguindo determinado conjunto de regras.

O Kernel do FreeRTOS permite a CPU trabalhar no modo não-preemptivo ou cooperativo.

## Tarefa

Pequeno algoritmo independente dos demais que corresponde a parte do sistema operacional.

## Estrutura de uma tarefa


xTaskCreate(
    taskOne,          /* Task function. */
    "TaskOne",        /* Descrição da task. */
    10000,            /* Tamanho da task em bytes. */
    NULL,             /* Parâmetro passado como entrada da task */
    1,                /* Prioridade da task. Quanto menor o valor, menor a prioridade. A task idle tem prioridade mínima */
    NULL);            /* Task handle. */



