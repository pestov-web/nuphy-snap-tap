RGB_MATRIX_EFFECT(game_mode)
RGB_MATRIX_EFFECT(position_mode)
RGB_MATRIX_EFFECT(snap_tap_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern rgb_config_t rgb_matrix_config;
// Подключаем enum и константы snap_tap_mode
#include "snap_tap_mode.h"
extern snap_tap_mode_t snap_tap_mode;  // Добавить extern для доступа к переменной

static bool game_mode(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        if(i<83)
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
    rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);       // ESC

    rgb_matrix_set_color(33, rgb.r, rgb.g, rgb.b);      // W
    rgb_matrix_set_color(47, rgb.r, rgb.g, rgb.b);      // D
    rgb_matrix_set_color(48, rgb.r, rgb.g, rgb.b);      // S
    rgb_matrix_set_color(49, rgb.r, rgb.g, rgb.b);      // A

    rgb_matrix_set_color(72, rgb.r, rgb.g, rgb.b);      // up
    rgb_matrix_set_color(80, rgb.r, rgb.g, rgb.b);      // right
    rgb_matrix_set_color(81, rgb.r, rgb.g, rgb.b);      // down
    rgb_matrix_set_color(82, rgb.r, rgb.g, rgb.b);      // left

    return rgb_matrix_check_finished_leds(led_max);
}

static bool position_mode(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        if(i<83)
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);

    rgb_matrix_set_color(50, rgb.r, rgb.g, rgb.b);      // F
    rgb_matrix_set_color(53, rgb.r, rgb.g, rgb.b);      // J
    rgb_matrix_set_color(72, rgb.r, rgb.g, rgb.b);      // up

    return rgb_matrix_check_finished_leds(led_max);
}

static bool snap_tap_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Сначала выключаем все клавиши
    for (uint8_t i = led_min; i < led_max; i++) {
        if(i<83)
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    // Определяем цвета для разных режимов
    RGB off_color = {0x40, 0x40, 0x40};      // Серый - выключен
    RGB cancel_color = {0xFF, 0x80, 0x00};   // Оранжевый - отмена
    RGB exclude_color = {0x00, 0xFF, 0x00};  // Зеленый - исключение

    RGB current_color;

    switch(snap_tap_mode) {
        case SNAP_TAP_OFF:
            current_color = off_color;
            break;
        case SNAP_TAP_CANCEL:
            current_color = cancel_color;
            break;
        case SNAP_TAP_EXCLUDE:
            current_color = exclude_color;
            break;
        default:
            current_color = off_color;
            break;
    }

    // Подсвечиваем клавиши WASD
    rgb_matrix_set_color(33, current_color.r, current_color.g, current_color.b);  // W
    rgb_matrix_set_color(47, current_color.r, current_color.g, current_color.b);  // D
    rgb_matrix_set_color(48, current_color.r, current_color.g, current_color.b);  // S
    rgb_matrix_set_color(49, current_color.r, current_color.g, current_color.b);  // A

    // Дополнительная индикация - подсвечиваем клавишу переключения режима (Q)
    rgb_matrix_set_color(32, current_color.r, current_color.g, current_color.b);  // Q

    // Плавная пульсация для активного режима через timer_read()
    // if (snap_tap_mode != SNAP_TAP_OFF) {
    //     uint16_t t = timer_read() % 2000; // 2 секунды на полный цикл
    //     // Треугольная волна: 0..1000 -> 0..255, 1000..2000 -> 255..0
    //     uint8_t pulse = (t < 1000) ? (t * 255 / 1000) : ((2000 - t) * 255 / 1000);
    //     // Микшируем с основным цветом
    //     uint8_t r = (current_color.r * pulse) / 255;
    //     uint8_t g = (current_color.g * pulse) / 255;
    //     uint8_t b = (current_color.b * pulse) / 255;
    //     rgb_matrix_set_color(32, r, g, b);
    // }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
