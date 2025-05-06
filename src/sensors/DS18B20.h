#ifndef DS18B20_H
#define DS18B20_H

void ds18b20_init(gpio_num_t gpio);
float ds18b20_get_temp();

#endif
