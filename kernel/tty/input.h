#include "../port.h"

typedef enum {
    SCANCODE_NONE = 0x00,
    SCANCODE_ESCAPE = 0x01,
    SCANCODE_1 = 0x02,
    SCANCODE_2 = 0x03,
    SCANCODE_3 = 0x04,
    SCANCODE_4 = 0x05,
    SCANCODE_5 = 0x06,
    SCANCODE_6 = 0x07,
    SCANCODE_7 = 0x08,
    SCANCODE_8 = 0x09,
    SCANCODE_9 = 0x0A,
    SCANCODE_0 = 0x0B,
    SCANCODE_MINUS = 0x0C,
    SCANCODE_EQUALS = 0x0D,
    SCANCODE_BACKSPACE = 0x0E,
    SCANCODE_TAB = 0x0F,
    SCANCODE_Q = 0x10,
    SCANCODE_W = 0x11,
    SCANCODE_E = 0x12,
    SCANCODE_R = 0x13,
    SCANCODE_T = 0x14,
    SCANCODE_Y = 0x15,
    SCANCODE_U = 0x16,
    SCANCODE_I = 0x17,
    SCANCODE_O = 0x18,
    SCANCODE_P = 0x19,
    SCANCODE_LEFT_BRACKET = 0x1A,
    SCANCODE_RIGHT_BRACKET = 0x1B,
    SCANCODE_ENTER = 0x1C,
    SCANCODE_LEFT_CONTROL = 0x1D,
    SCANCODE_A = 0x1E,
    SCANCODE_S = 0x1F,
    SCANCODE_D = 0x20,
    SCANCODE_F = 0x21,
    SCANCODE_G = 0x22,
    SCANCODE_H = 0x23,
    SCANCODE_J = 0x24,
    SCANCODE_K = 0x25,
    SCANCODE_L = 0x26,
    SCANCODE_SEMICOLON = 0x27,
    SCANCODE_APOSTROPHE = 0x28,
    SCANCODE_GRAVE = 0x29,
    SCANCODE_LEFT_SHIFT = 0x2A,
    SCANCODE_BACKSLASH = 0x2B,
    SCANCODE_Z = 0x2C,
    SCANCODE_X = 0x2D,
    SCANCODE_C = 0x2E,
    SCANCODE_V = 0x2F,
    SCANCODE_B = 0x30,
    SCANCODE_N = 0x31,
    SCANCODE_M = 0x32,
    SCANCODE_COMMA = 0x33,
    SCANCODE_PERIOD = 0x34,
    SCANCODE_SLASH = 0x35,
    SCANCODE_RIGHT_SHIFT = 0x36,
    SCANCODE_KEYPAD_MULTIPLY = 0x37,
    SCANCODE_LEFT_ALT = 0x38,
    SCANCODE_SPACE = 0x39,
    SCANCODE_CAPS_LOCK = 0x3A,
    SCANCODE_F1 = 0x3B,
    SCANCODE_F2 = 0x3C,
    SCANCODE_F3 = 0x3D,
    SCANCODE_F4 = 0x3E,
    SCANCODE_F5 = 0x3F,
    SCANCODE_F6 = 0x40,
    SCANCODE_F7 = 0x41,
    SCANCODE_F8 = 0x42,
    SCANCODE_F9 = 0x43,
    SCANCODE_F10 = 0x44,
    SCANCODE_NUM_LOCK = 0x45,
    SCANCODE_SCROLL_LOCK = 0x46,
    SCANCODE_KEYPAD_7 = 0x47,
    SCANCODE_KEYPAD_8 = 0x48,
    SCANCODE_KEYPAD_9 = 0x49,
    SCANCODE_KEYPAD_MINUS = 0x4A,
    SCANCODE_KEYPAD_4 = 0x4B,
    SCANCODE_KEYPAD_5 = 0x4C,
    SCANCODE_KEYPAD_6 = 0x4D,
    SCANCODE_KEYPAD_PLUS = 0x4E,
    SCANCODE_KEYPAD_1 = 0x4F,
    SCANCODE_KEYPAD_2 = 0x50,
    SCANCODE_KEYPAD_3 = 0x51,
    SCANCODE_KEYPAD_0 = 0x52,
    SCANCODE_KEYPAD_PERIOD = 0x53,
} Scancode;

char scancode_to_ascii[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',    // 0x00 - 0x0E
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',      // 0x0F - 0x1C
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',  0, '\\',    // 0x1D - 0x2B
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',  0, '*', 0,  ' ',          // 0x2C - 0x39
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  '-',  0,  0,  0,  '+',          // 0x3A - 0x4E
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0               // 0x4F - 0x53
};

int is_key_pressed() {
    return inb(0x64) & 1;
}

unsigned char get_key() {
    if (!is_key_pressed()) return 0;
    return inb(0x60);
}

int ispressed(int scan) {
    return get_key() == scan;
}

char getch() {
    while (1) {
        unsigned char scan = get_key();
        if (scancode_to_ascii[scan] != 0)
            return scancode_to_ascii[scan];
    }
}