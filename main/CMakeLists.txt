set(component_srcs "gatts_demo.c" "engine.c" "keyboard.c" "ble_profiles.c" "oled_ssd1306.c")

idf_component_register(SRCS "${component_srcs}"
                    INCLUDE_DIRS "." "include" )
