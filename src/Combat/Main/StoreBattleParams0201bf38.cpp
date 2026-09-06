#include <globaldefs.h>

ARM void SetOrClearBit(unsigned char* obj, int bit, int set);

// USA: func_0201bf38
ARM void StoreBattleParams0201bf38(unsigned char* obj, int set, int a, int b, unsigned short c) {
    SetOrClearBit(obj, 0, set);
    obj[0x2745] = a;
    obj[0x2746] = b;
    *(unsigned short*)(obj + 0x2748) = c;
}
