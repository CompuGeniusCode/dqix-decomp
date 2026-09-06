#include <globaldefs.h>

struct Struct020349c8;
extern "C" float _ZNK10AlphaTween9GetTargetEv(struct Struct020349c8*);

// USA: func_02049fec
ARM float GetScaledField0x6002049fec(char* obj) {
    char* x = *(char**)(obj + 0x13c);
    if (x == NULL) return 0.0f;
    return _ZNK10AlphaTween9GetTargetEv((struct Struct020349c8*)(x + 0x60));
}
