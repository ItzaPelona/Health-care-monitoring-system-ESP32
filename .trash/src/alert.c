#include "alert.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_RED GPIO_NUM_25
#define BUZZER GPIO_NUM_26

void activar_alerta(float temp) {
    gpio_set_level(LED_RED, 1);
    gpio_set_level(BUZZER, 1);
    ESP_LOGW("ALERTA", "Temperatura alta: %.2f°C", temp);
}

void desactivar_alerta(void) {
    gpio_set_level(LED_RED, 0);
    gpio_set_level(BUZZER, 0);
}