#include <globaldefs.h>

struct DivHw020c2cf0 {
    volatile unsigned short cnt;
    unsigned char _pad[0xe];
    volatile unsigned int numerLo;
    volatile unsigned int numerHi;
    volatile unsigned int denomLo;
    volatile unsigned int denomHi;
};

// USA: func_020c2cf0
extern "C" ARM void fix32_QueueComputeQuotient(unsigned int numerHi, unsigned int denomLo) {
    struct DivHw020c2cf0* div = (struct DivHw020c2cf0*)0x4000280;
    div->cnt = 1;
    div->numerLo = 0;
    div->numerHi = numerHi;
    div->denomLo = denomLo;
    div->denomHi = 0;
}
