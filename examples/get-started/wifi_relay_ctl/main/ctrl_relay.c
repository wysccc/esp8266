/**
 * relay ctrl
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "ctrl_relay.h"

#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_system.h"

#define RELAY_IO_0    RELAY_CTRL0
#define RELAY_IO_1    RELAY_CTRL1
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<RELAY_IO_0) | (1ULL<<RELAY_IO_1))

void relay_init(void)
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
}

void relay_ctrl(int relay_num, int delay_ms)
{
    int io_num = relay_num ? RELAY_IO_1 : RELAY_IO_0;

    gpio_set_level(io_num, 0);
    vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    gpio_set_level(io_num, 1);
}

