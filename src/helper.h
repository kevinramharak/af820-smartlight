#ifndef LAMP_HELPER_H
#define LAMP_HELPER_H

#include <cstdint>

uint16_t incrementCounter(uint16_t old) {
    if(old == UINT16_MAX)
        return 1;
    else
        return ++old;
}

uint8_t myRand() {
    return (uint8_t)(rand()%(60-0 + 1));
}

void print(const uint8_t * msg, int length) {
    for(uint8_t i = 0; i < length; i++)
        printf("%02X ", msg[i]);
    printf("\n");
}

#endif //LAMP_HELPER_H