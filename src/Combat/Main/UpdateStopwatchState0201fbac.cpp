#include <globaldefs.h>

struct Stopwatch0201fbac {
    unsigned char state;    // +0
    unsigned char b1;       // +1
    unsigned char b2;       // +2
    unsigned char b3;       // +3
    unsigned short s4;      // +4
    unsigned short s6;      // +6
    int w8;                 // +8
    int wc;                 // +0xc
    int w10;                // +0x10
};

// USA: func_0201fbac
ARM void UpdateStopwatchState0201fbac(struct Stopwatch0201fbac* t) {
    unsigned char st = t->state;
    if (st == 1 || st == 4) {
        t->b1 = 3;
    } else if (st == 2) {
        t->w10 = 0x43080000;
    }
    t->s4 = 0;
}
