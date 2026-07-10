#include <globaldefs.h>

struct Obj0202f9b4;
void HalveCounterField0x788(struct Obj0202f9b4* obj);

extern char data_02104304;

// USA: func_0202f7e8
ARM void HalveGlobalObjectCounter(void) {
    struct Obj0202f9b4* obj = *(struct Obj0202f9b4**)(&data_02104304 + 4);
    if (obj == NULL) return;
    HalveCounterField0x788(obj);
}
