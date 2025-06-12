#include "tty/print.h"
#include "tty/cls.h"
#include "tty/input.h"

void main() {
    cls();
    printc("(\x01\x0axaha-os\x01\x0f) Booted!");
    char s[1];
    s[0] = getch();
    printc(s);
}