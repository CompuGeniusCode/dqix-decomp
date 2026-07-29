#include <globaldefs.h>

struct Block8_020c6938 { unsigned int v[8]; };
struct Pair8_020c6938 { Block8_020c6938 a; Block8_020c6938 b; };

// USA: func_020c6938
ARM void CopyLastBlock8_020c6938(Pair8_020c6938* src, Block8_020c6938* dst) {
    *dst = src->a;
    *dst = src->b;
}
