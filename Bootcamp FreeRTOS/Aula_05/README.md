# AULA 05 - Bootcamp ESP 32 Free RTOS

Aula 05 sobre programação FreeRTOS usando ESP 32 e Arduino IDE.

## Task Notification

Tasks  com uma variável de notificação de 32 bits.

Uma task notification corresponde a um evento enviado diretamente a uma tarefa, podendo desbloqueá-la.

Podem ser usados como Semáforos binários, semáforos contadores e grupos de eventos

A notificação é enviada de forma direta; não precisando passar por itens intermediários, aumentando em 40% a velocidade de processamento.

Também precisa ser habilitado

## Vantagens do uso de Task Notification

    1. Mais rápido que filas e semáforos;
    2. Menor consumo de memória RAM

## Desvantagens do uso de Task Notification

    1. Não há como enviar uma notificação a uma interrupção. MAS pode fazer a interrução disparar a notificação
    2. Não há como enviar notificação para mais de uma tarefa ao mesmo tempo
    3. Não há como armazenar os dados enviados. Se o buffer estiver cheio, não há como utilizar a task notification