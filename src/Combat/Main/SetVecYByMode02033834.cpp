#include <globaldefs.h>

struct Obj02033874;

struct Obj02033834 {
    char pad0[0xae];
    short fae;           // 0xae
    char pad1[0x0e];     // 0xb0..0xbd
    unsigned char mode;  // 0xbe
    char pad2[0x05];     // 0xbf..0xc3
    unsigned short fc4;  // 0xc4
};

extern "C" short func_02030f30(int);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

// USA: func_02033834
ARM void SetVecYByMode02033834(struct Obj02033834* obj, int arg) {
    if (obj->mode == 4 || obj->mode == 3) {
        SetVecYFromValue02033874((struct Obj02033874*)obj, arg);
    } else {
        obj->fae = func_02030f30(arg);
    }
    obj->fc4 &= ~0x8000;
}
