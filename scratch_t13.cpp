#include <globaldefs.h>
struct S8 { short a,b,c,d; };
extern S8 arrS[];
extern "C" ARM short test13(unsigned int i) {
    return arrS[(unsigned char)i].a;
}
