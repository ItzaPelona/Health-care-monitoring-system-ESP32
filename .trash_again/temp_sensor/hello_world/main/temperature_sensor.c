#include <stdio.h>
#include "temperature_sensor.h"
#include "ds18b20.h"
#include "rom/ets_sys.h"
#include "esp_log.h"

#define SENSOR_GPIO 4
#define MAX_DEVICES 1

static const char *TAG = "DALLAS";

static DS18B20_Info *ds18b20_info = NULL;

void dallas_init(void)
{
    gpio_set_pull_mode(SENSOR_GPIO, GPIO_PULLUP_ONLY); // Requiere pull-up

    OneWireBus *owb;
    owb = owb_rmt_initialize(SENSOR_GPIO, RMT_CHANNEL_1, RMT_CHANNEL_0);
    owb_use_crc(owb, true);  // Requiere CRC

    ds18b20_info = ds18b20_malloc();
    ds18b20_init(ds18b20_info, owb);
    ds18b20_use_crc(ds18b20_info, true);
    ds18b20_set_resolution(ds18b20_info, DS18B20_RESOLUTION_12_BIT);
    ESP_LOGI(TAG, "Sensor Dallas inicializado");
}

float dallas_read_temperature(void)
{
    float temp;
    ds18b20_convert_all(ds18b20_info);
    ets_delay_us(750000); // Espera conversión

    ds18b20_read_temp(ds18b20_info, &temp);
    return temp;
}
