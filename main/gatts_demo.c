/*
* Electronic Cats AppsecPwn CTF 2024

* This file is part of the Electronic Cats AppsecPwn CTF 2024 project.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_vfs_eventfd.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "hal/uart_types.h"

#include "esp_bt.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"
#include "esp_gatt_common_api.h"
#include "esp_gatts_api.h"

#include "engine.h"
#include "ble_profiles.h"
#include "oled_ssd1306.h"
#include "keyboard.h"
#include "button_helper.h"

#include "sdkconfig.h"

#define TAG_MAIN "EC_APPSECPWN"

struct gattc_profile_inst gatts_profile_tab[DEVICE_PROFILES] = {
    [DEVICE_PROFILE] = {
        .gattc_cb = gatts_profiles_event_handler,
        .gattc_if = ESP_GATT_IF_NONE,
    }
};

void app_main(void) {
    keyboard_init();
    init_i2c_bus();
    init_ble_task();
}
