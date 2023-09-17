#include "Sound.h"
#include "../Config/config.h"
#include "pico/stdlib.h"
extern CONFIG CONFIG_;
void sound_ms(unsigned int time_ms) {
    for (unsigned int i = 0; i < time_ms / 2 * CONFIG_.FREQUENCY; i++) {
        gpio_put(CONFIG_.PIN, true);
        sleep_ms(CONFIG_.FREQUENCY);
        gpio_put(CONFIG_.PIN, false);
        sleep_ms(CONFIG_.FREQUENCY);
    }
}