#include <iostream>
#include <string>
using std::string;
enum Mode{WORD, MORSE};

class CONFIG {
public:
    const uint PIN; // output GPIO number
    const string word; // edit here while using WORD mode
    const string morse; // edit here while using MORSE mode
    const int FREQUENCY;
    Mode MODE;

    CONFIG():
        PIN(25),
        word(""),
        morse(""),
        FREQUENCY(0),
        MODE(MORSE)
    {}

    CONFIG(const uint PIN_, const string & word_, const string & morse_,
           const int FREQUENCY_, const Mode MODE_):
        PIN(PIN_),
        word(word_),
        morse(morse_),
        FREQUENCY(FREQUENCY_),
        MODE(MODE_)
    {}

    ~CONFIG() = default;
};