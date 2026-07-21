#include <globaldefs.h>
struct S8 { short a,b,c,d; };
extern S8 arrS[];
extern "C" ARM short test12(unsigned char i) {
    return arrS[i].a;
}
