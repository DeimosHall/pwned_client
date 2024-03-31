#ifndef BLE_PROFILES_H
#define BLE_PROFILES_H
#include "esp_bt.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"
#include "esp_gatt_common_api.h"
#include "esp_gatts_api.h"
#include "esp_gattc_api.h"
#include "engine.h"

#define GATTC_TAG "EC_APPSECPWN_BLE"

//GATT Client
#define REMOTE_SERVICE_USERNAME_UUID 0x00FF
#define REMOTE_NOTIFY_CHAR_UUID    0xFF01
#define PROFILE_NUM      1
#define PROFILE_A_APP_ID 0
#define INVALID_HANDLE   0
#define REMOTE_BOARD_ID "EC_APPSECPWN_RED"

//GATT Server
// Device Profiles
#define DEVICE_PROFILES 1  // 4 Profiles -> OWASP_PROFILE, USERNAME, ATTACK, POINTS
#define DEVICE_PROFILE_USERNAME 0
#define DEVICE_PROFILE_OWASP 1


typedef struct {
    uint8_t* prepare_buf;
    int prepare_len;
} prepare_type_env_t;

struct gattc_profile_inst {
    esp_gattc_cb_t gattc_cb;
    uint16_t gattc_if;
    uint16_t app_id;
    uint16_t conn_id;
    uint16_t service_start_handle;
    uint16_t service_end_handle;
    uint16_t char_handle;
    esp_bd_addr_t remote_bda;
};

// GATT Client
static void esp_gap_cb(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);
static void esp_gattc_cb(esp_gattc_cb_event_t event, esp_gatt_if_t gattc_if, esp_ble_gattc_cb_param_t *param);
extern void gatts_profile_username_event_handler(esp_gattc_cb_event_t event, esp_gatt_if_t gattc_if, esp_ble_gattc_cb_param_t *param);

extern void get_profile_owasp_uint8(uint8_t* response_information, OWASPProfile *profile);


typedef struct {
    esp_gattc_cb_t gattc_cb;
    uint16_t gattc_if;
    uint16_t app_id;
    uint16_t conn_id;
    uint16_t service_start_handle;
    uint16_t service_end_handle;
    uint16_t char_handle;
    esp_bd_addr_t remote_bda;
}gattc_profile_inst;

extern struct gattc_profile_inst gatts_profile_tab[DEVICE_PROFILES];

void init_ble_task(void);
#endif // BLE_PROFILES_H