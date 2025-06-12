#pragma once
#include "print.h"

void cls() {
    volatile char *_video = (volatile char*)0xB8000;
    for (int i = 0; i < 80 * 25; i++)
    {
        *_video++ = ' ';
        *_video++ = text_colour;
    }
}