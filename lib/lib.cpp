#include "lib.h"

void sortAndReplace(std::string& input) {
    std::sort(input.rbegin(), input.rend()); //TODO: manually ??

    std::string result;

    for(char i : input) {
        if((i % 2) == 0) {
            result += "KB";
        } else {
            result += i;
        }
    }

    input = result;
}

int getSumNumbers(const std::string& input) {
    int result = 0;

    for(int i = 0; i < input.length(); ++i) {
        if(input[i] >= '0' && input[i] <= '9') {
            result += input[i] - '0';
        } else {
            ++i;
        }
    }

    return result;
}

bool analyse(const std::string& input) {
    return (input.length() > 2) && !(input.length() % 32);
}
