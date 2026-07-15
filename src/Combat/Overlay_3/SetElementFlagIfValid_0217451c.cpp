// USA: func_ov003_0217451c
#include <globaldefs.h>

struct Obj2081;
void SetElementFlag0x40(struct Obj2081* obj, int key, int enable);

ARM void SetElementFlagIfValid_0217451c(char* obj) {
    short val = *(short*)(obj + 0xf00 + 0xfc);
    if (val < 0) return;
    SetElementFlag0x40(*(struct Obj2081**)(obj + 0x89c), val, 1);
    *(short*)(obj + 0xf00 + 0xfc) = -1;
}
