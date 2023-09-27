# AULA 04 - Bootcamp ESP 32 Free RTOS

Aula 04 sobre programação FreeRTOS usando ESP 32 e Arduino IDE.

## Eventos

Permite que eventos sejam comunicados às tarefas. Eventos podem desbloquear uma ou mais tarefas. Além disso, a combinação de eventos podem sincronizar várias tarefas dentro da aplicação.

## EVENT GROUPS, EVENT FLAGS e EVENT BITS

Os eventos recebem bits que são setados e verificados por meio de flags. A task fica no estado bloqueado…aguardando os eventos

O grupo de eventos também pode ser deletado

São uma importante feature do FreeRTOS. Os Event Groups são usados para comunicar a ocorrência de eventos às tarefas. Eles permitem a sincronização de uma tarefa com um ou mais eventos. Além disso, pode ser usado para desbloquear várias tarefas que estão aguardando o evento ou vários eventos.

Pode ser usado para sincronizar várias tarefas usando um único evento ou vários eventos. Além disso, pode bloquear uma única tarefa aguardando a ocorrência de vários eventos e desbloquear a tarefa quando o conjunto de eventos ocorrer

## Por quê usar Event Groups

O uso de event groups permite a economia de memória RAM. Uma vez que você pode substituir vários semáforos binários por um único evento ou grupos de eventos.

Os eventos tem o sinalizador de eventos (valor booleano de "0" ou "1" que mostram a ocorrência ou não ocorrência de um evento) e os bits de eventos. Um grupo de eventos corresponde a um grupo de sinalizadores de eventos.


## O exemplo

O exemplo usa eventos para gerenciar o uso da rede WiFi do ESP 32