#include <device.h>
#include <drivers/behavior.h>
#include <zmk/behavior.h>

static bool state = false;

static int toggle_xy_press(const struct zmk_behavior_binding *binding,
                           struct device *dev, uint32_t param) {
    if (state) {
        zmk_behavior_key_code_press(KEY_X);
        zmk_behavior_key_code_release(KEY_X);
    } else {
        zmk_behavior_key_code_press(KEY_Y);
        zmk_behavior_key_code_release(KEY_Y);
    }
    state = !state;
    return 0;
}

static const struct zmk_behavior_driver_api toggle_xy_api = {
    .binding_press = toggle_xy_press,
};

ZMK_BEHAVIOR(toggle_xy, toggle_xy_api);
