#include "esp_log.h"
#include "esp_bt.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"
#include "esp_gatt_common_api.h"
#include "esp_gatts_api.h"
#include "keyboard.h"
#include "button_helper.h"
#include "engine.h"
#include "ble_profiles.h"


int index_position = 0;


void button_init(uint32_t button_num, uint8_t mask) {
    button_config_t btn_cfg = {
        .type = BUTTON_TYPE_GPIO,
        .gpio_button_config = {
            .gpio_num = button_num,
            .active_level = BUTTON_ACTIVE_LEVEL,
        },
    };
    button_handle_t btn = iot_button_create(&btn_cfg);
    assert(btn);
    esp_err_t err = iot_button_register_cb(btn, BUTTON_PRESS_DOWN, button_event_cb, (void*)(BUTTON_PRESS_DOWN | mask));
    err |= iot_button_register_cb(btn, BUTTON_PRESS_UP, button_event_cb, (void*)(BUTTON_PRESS_UP | mask));
    err |= iot_button_register_cb(btn, BUTTON_PRESS_REPEAT, button_event_cb, (void*)(BUTTON_PRESS_REPEAT | mask));
    err |= iot_button_register_cb(btn, BUTTON_PRESS_REPEAT_DONE, button_event_cb, (void*)(BUTTON_PRESS_REPEAT_DONE | mask));
    err |= iot_button_register_cb(btn, BUTTON_SINGLE_CLICK, button_event_cb, (void*)(BUTTON_SINGLE_CLICK | mask));
    err |= iot_button_register_cb(btn, BUTTON_DOUBLE_CLICK, button_event_cb, (void*)(BUTTON_DOUBLE_CLICK | mask));
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_START, button_event_cb, (void*)(BUTTON_LONG_PRESS_START | mask));
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_HOLD, button_event_cb, (void*)(BUTTON_LONG_PRESS_HOLD | mask));
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_UP, button_event_cb, (void*)(BUTTON_LONG_PRESS_UP | mask));
    ESP_ERROR_CHECK(err);
}

void keyboard_init() {
    button_init(BOOT_BUTTON_PIN, BOOT_BUTTON_MASK);
    button_init(LEFT_BUTTON_PIN, LEFT_BUTTON_MASK);
    button_init(RIGHT_BUTTON_PIN, RIGHT_BUTTON_MASK);
    button_init(UP_BUTTON_PIN, UP_BUTTON_MASK);
    button_init(DOWN_BUTTON_PIN, DOWN_BUTTON_MASK);
}

void button_event_cb(void* arg, void* data) {
    uint8_t button_name = (((button_event_t)data) >> 4);   // >> 4 to get the button number
    uint8_t button_event = ((button_event_t)data) & 0x0F;  // & 0x0F to get the event number without the mask
    // const char* button_name_str = button_name_table[button_name];
    // const char* button_event_str = button_event_table[button_event];
    //ESP_LOGI(TAG_KEYBOARD, "Button: %s, Event: %s", button_name_str, button_event_str);

    switch (button_name) {
        case BOOT:
            break;
        case LEFT:
            if (button_event == BUTTON_PRESS_DOWN) {
                ESP_LOGI(TAG_KEYBOARD, "Left button pressed");
            }
            break;
        case RIGHT: {
            if (button_event == BUTTON_PRESS_DOWN) {
                ESP_LOGI(TAG_KEYBOARD, "Right button pressed");
                uint8_t *username_char[sizeof(OWASPA01.vuln->cwe)];
                get_owasp_profile_cwe_uint8(&username_char, getOWASPProfile(index_position));
            }
            break;
        }
        case UP: {
            if (button_event == BUTTON_PRESS_DOWN) {
                ESP_LOGI(TAG_KEYBOARD, "Up button pressed");
                if (index_position > 0) {
                    index_position--;
                } else {
                    index_position = 9;
                }
                ESP_LOGI(TAG_KEYBOARD, "Index position: %d - OWASP Profile: %s", index_position, getOWASPProfile(index_position)->vuln->cwe);
            }
            break;
        }
        case DOWN: {
            if (button_event == BUTTON_PRESS_DOWN) {
                ESP_LOGI(TAG_KEYBOARD, "Down button pressed");
                if (index_position < 9) {
                    index_position++;
                } else {
                    index_position = 0;
                }
                ESP_LOGI(TAG_KEYBOARD, "Index position: %d - OWASP Profile: %s", index_position, getOWASPProfile(index_position)->vuln->cwe);
            }
            break;
        }
    }
}