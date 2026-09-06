#include <globaldefs.h>

struct Obj02074af4 {
    short bg0, pad0;
    short bg1, pad1;
    short bg2, pad2;
    short bg3, pad3;
    unsigned char saved;
};

// USA: func_02074af4
ARM void SaveBGControlRegs02074af4(Obj02074af4* obj) {
    if (obj->saved == 0) {
        volatile unsigned short* hw = (volatile unsigned short*)0x4000008;
        unsigned short t;

        volatile short v0, v1, v2, v3;

        t = hw[0];
        v0 = t;
        t = v0;
        obj->bg0 = t;

        t = hw[1];
        v1 = t;
        t = v1;
        obj->bg1 = t;

        t = hw[2];
        v2 = t;
        t = v2;
        obj->bg2 = t;

        t = hw[3];
        v3 = t;
        t = v3;
        obj->bg3 = t;

        obj->saved = 1;
    }
}
