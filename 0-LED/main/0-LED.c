#include <stdio.h>

#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    esp_err_t rc = ESP_OK;
    rc = gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    if (rc != ESP_OK) {
        printf("Failed to set GPIO direction!\n");
    }

    while (1) {
        rc = gpio_set_level(GPIO_NUM_2, 1);
        if (rc != ESP_OK) {
            printf("Failed to set GPIO level!\n");
        } else {
            printf("Set level high.\n");
        }

        vTaskDelay(pdMS_TO_TICKS(1000));

        rc = gpio_set_level(GPIO_NUM_2, 0);
        if (rc != ESP_OK) {
            printf("Failed to set GPIO level!\n");
        } else {
            printf("Set level low.\n");
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
