#include <globaldefs.h>

struct Stopwatch0201f9e8 {
    unsigned char state;    // +0
    unsigned char b1;       // +1
    unsigned char b2;       // +2
    unsigned char b3;       // +3
};

// Tail-calls func_0201fa00 (ResetStopwatch0201fa00).
extern "C" void ResetStopwatch0201fa00(struct Stopwatch0201f9e8* t);

// USA: func_0201f9e8
ARM void InitStopwatch0201f9e8(struct Stopwatch0201f9e8* t) {
    t->b2 = 0;
    t->b3 = 0;
    ResetStopwatch0201fa00(t);
}
