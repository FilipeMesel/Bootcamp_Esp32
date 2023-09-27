#include <Arduino.h>
#include <WiFi.h>

EventGroupHandle_t wifiEventGroup;
const int WIFI_CONNECTED_BIT = BIT0;

void taskConnectWiFi(void *parameter) {
  while (true) {
    WiFi.begin("EBST_NETWORK_2.4GHZ", "@Ebst20.22");
    
    if (xEventGroupWaitBits(wifiEventGroup, WIFI_CONNECTED_BIT, pdTRUE, pdTRUE, portMAX_DELAY)) {
      Serial.println("Conexão Wi-Fi bem-sucedida!");
    } else {
      Serial.println("Falha na conexão Wi-Fi.");
    }

    vTaskDelay(60000 / portTICK_PERIOD_MS); // Tentar reconectar a cada 60 segundos
  }
}

void onWiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case SYSTEM_EVENT_STA_GOT_IP:
      xEventGroupSetBits(wifiEventGroup, WIFI_CONNECTED_BIT);
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      xEventGroupClearBits(wifiEventGroup, WIFI_CONNECTED_BIT);
      break;
  }
}

void setup() {
  Serial.begin(115200);
  wifiEventGroup = xEventGroupCreate();

  WiFi.onEvent(onWiFiEvent);
  
  xTaskCreatePinnedToCore(
      taskConnectWiFi,
      "Conectar Wi-Fi",
      10000,
      NULL,
      1,
      NULL,
      0);
}

void loop() {
  // O loop principal não faz nada no FreeRTOS
}
