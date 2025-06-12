#pragma once

volatile char *video = (volatile char*)0xB8000;
short int text_colour = 0x0f;

void printc(char *string) {
    int colour_mode = 0;

    while (*string != 0) {
        char current = *string++;

        if (current == '\x01')
            colour_mode = 1;
        else if (current == '\n' && colour_mode != 1) {
            for (int i = 0; i < ((video - (volatile char*)0xB8000) / 2) % 80; i++)
            {
                *video++ = ' ';
                *video++ = text_colour;
            }

        }
        else if (colour_mode) {
            text_colour = current;
            colour_mode = 0;
        } else {
            *video++ = current;
            *video++ = text_colour;
        }
    }
}