#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

extern "C" {
    void func_0201c724(int a, void* b, int c, int d);
    void _ZN6Zone3D11LoadMapAMBLEv(void* obj);
}

struct Obj02013fb4 {
    unsigned short field0;
    char pad[0x430 - 2];
    int field0x430;
};

// USA: func_02013fb4
ARM int ApplyAndClearPendingEntry02013fb4(struct Obj02013fb4* obj) {
    if (obj->field0x430 < 0) {
        return 1;
    }

    int listPtr = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(obj->field0x430))) {
        return 0;
    }

    int out1, out2;
    ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(obj->field0x430), (void**)(&out1), (unsigned int*)(&out2));
    func_0201c724(obj->field0, (char*)obj + 0xc, out1, out2);
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(obj->field0x430));
    obj->field0x430 = -1;
    _ZN6Zone3D11LoadMapAMBLEv(obj);
    return 1;
}
