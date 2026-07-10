#include <globaldefs.h>

struct Obj02052338 {
    char pad0[0x40];
    unsigned short field40;
};

extern "C" int func_020b72ac(int, int, struct Obj02052338*);

// USA: func_02052338
ARM int Forward02052338(struct Obj02052338* obj, int arg1) {
    return func_020b72ac(arg1, obj->field40, obj);
}
