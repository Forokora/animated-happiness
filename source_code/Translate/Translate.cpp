#include "Translate.h"
#include <iostream>
#include <string>
#include <map>

std::map<const char, const std::string> MorseTable {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
        {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G',"--."}, {'H', "...."}, {'I', ".."},
        {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P',".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"},
        {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"},
        {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."}, {'0', "-----"},
        {' ', ""}
};

const std::string & translate(const std::string & str) {
    auto * back_val = new std::string("");
    std::string temp = str;
    size_t num = temp.size();
    for (int i = 0; i < static_cast<int>(num); i++)
        if (islower(temp[i])) temp[i] = toupper(temp[i]);
    for (int j = 0; j < static_cast<int>(num); j++) {
        *back_val += MorseTable.find(temp[j])->second;
        if (temp[j] != ' ') *back_val += "/";
        else continue;
    }
    return *back_val;
}