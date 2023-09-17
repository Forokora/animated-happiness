#include <string>
#include "Config/config.h"
#include "pico/stdlib.h"
#include "Translate/Translate.h"
#include "Sound/Sound.h"
#include <cstdlib>
extern CONFIG CONFIG_;
using std::string;

const int long_ = 250;
const int short_ = 80;
const int end_ = 300;

int main()
{
    gpio_init(CONFIG_.PIN);
    gpio_set_dir(CONFIG_.PIN, GPIO_OUT);
    stdio_init_all();

    string content;
    size_t num;

    if (CONFIG_.MODE == WORD) content = translate(CONFIG_.word);
    else if (CONFIG_.MODE == MORSE) content = CONFIG_.morse;
    else exit(EXIT_FAILURE);

    num = content.size();

    sleep_ms(5000);
    while (true) {
        for (int i = 0; i < static_cast<int>(num); i++) {
            if (content[i] == '-') {
                sound_ms(long_);
                printf("-");
                sleep_ms(200);
            }
            else if (content[i] == '.') {
                sound_ms(short_);
                printf(".");
                sleep_ms(200);
            }
            else if (content[i] == '/') {
                sleep_ms(end_);
                printf("/");
            }
        }
        sleep_ms(5000);
        printf("\n");
    }
}