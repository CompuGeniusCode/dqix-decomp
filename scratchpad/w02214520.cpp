#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" void func_020ca3ec(int value, void* dst, int size);
int Advance_02214600(void* obj);
extern "C" int func_ov031_02214854(void* obj);
extern "C" int func_ov031_022148e4(void* obj);
extern "C" int func_ov031_02214660(void* obj);

struct Obj02214520 {
    char pad[0xd0f];
    unsigned char fieldD0f;
    unsigned char fieldD10;
};

// USA: func_ov031_02214520
extern "C" ARM unsigned char func_ov031_02214520(int mode) {
    Obj02214520* obj = (Obj02214520*)func_ov031_022133f8(0x10);
    switch (mode) {
    case 0:
        func_020ca3ec(0, (char*)obj + 0x300, 0x144);
        obj->fieldD10 = (unsigned char)Advance_02214600(obj);
        break;
    case 1:
        obj->fieldD10 = (unsigned char)func_ov031_02214854(obj);
        obj->fieldD0f = (unsigned char)func_ov031_022148e4(obj);
        break;
    case 2:
        func_020ca3ec(0, (char*)obj + 0x300, 0x144);
        obj->fieldD0f = 0;
        obj->fieldD10 = (unsigned char)func_ov031_02214660(obj);
        break;
    }
    return obj->fieldD10;
}
