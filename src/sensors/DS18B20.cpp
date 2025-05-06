#include "ds18b20.h"
#include "owb.h"
#include "owb_rmt.h"
#include "ds18b20.h"
#include "esp_log.h"

static const char *TAG = "DS18B20";
static DS18B20_Info *sensor = NULL;

void ds18b20_init(gpio_num_t gpio) {
    OneWireBus *owb;
    owb = owb_rmt_initialize(gpio, RMT_CHANNEL_1, RMT_CHANNEL_0);
    owb_use_crc(owb, true);

    sensor = ds18b20_malloc();
    ds18b20_init(sensor, owb);
    ds18b20_use_crc(sensor, true);
    ds18b20_set_resolution(sensor, DS18B20_RESOLUTION_12_BIT);
    ds18b20_convert_all(owb);
}

float ds18b20_get_temp() {
    float temp = 0;
    ds18b20_wait_for_conversion(sensor);
    ds18b20_read_temp(sensor, &temp);
    ESP_LOGI(TAG, "Temperatura: %.2f°C", temp);
    return temp;
}
