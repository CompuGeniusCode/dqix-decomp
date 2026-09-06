#include <globaldefs.h>

struct Stopwatch0201fa00 {
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

extern "C" {
// USA: func_0201fa00
ARM void ResetStopwatch0201fa00(struct Stopwatch0201fa00* t) {
    t->state = 1;
    t->b1 = 0;
    t->s4 = 0;
    t->w10 = 0x43300000;
    t->w8 = 0;
    t->wc = 0;
}
}
