idf_component_register(SRCS "main.c" "temperature_sensor.c"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES spi_flash esp32-ds18b20 esp32-owb)
