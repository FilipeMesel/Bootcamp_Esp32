# AULA 03 - Bootcamp ESP 32 Free RTOS

Aula 03 sobre programação FreeRTOS usando ESP 32 e Arduino IDE.

## Semáforos

São estruturas de dados que permitem a organização no compartilhamento de recursos do micrcontrolador. Por exemplo, duas tasks não podem usar a mesma porta digital ao mesmo tempo. Isso faria o ESP 32 reiniciar. Os semáforos bloqueiam e liberam o uso dos recursos

## Tipos de Semáforos

    1. De Contagem (EX 01): Um semáforo que mantém uma contagem de tokens, permitindo que um número específico de tarefas acesse um recurso simultaneamente.

    2. Binários (EX 02): Um semáforo que pode estar em um de dois estados, permitindo ou bloqueando o acesso a um recurso compartilhado, adequado para exclusão mútua entre tarefas.

    3. Mutex (EX 03): Um semáforo especializado para garantir a exclusão mútua, usado para proteger recursos compartilhados, garantindo que apenas uma tarefa por vez possa acessá-los. O SEMÁFORO MUTEX NÃO PODE SER USADO COM INTERRUPÇÃO