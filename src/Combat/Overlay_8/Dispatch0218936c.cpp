#include <globaldefs.h>

extern "C" void func_0205d0e0(void* obj);
extern "C" void func_ov008_021895a8(void* obj);
extern "C" void func_ov008_02189c70(void* obj);
extern "C" void func_ov008_0218af80(void* obj);
extern "C" void func_ov008_02184754(void* obj);
extern "C" void func_ov008_0218b084(void* obj);

struct Manager0218936c {
    char pad[0xe99];
    signed char sub99;
    signed char sub9a;
    signed char sub9b;
    char pad2[0xeb8 - 0xe9c];
    unsigned char fieldEb8;
};

// USA: func_ov008_0218936c
ARM unsigned char Dispatch0218936c(Manager0218936c* obj) {
    func_0205d0e0((char*)obj + 0x18);
    switch (obj->sub99) {
    case 0:
        func_ov008_021895a8(obj);
        break;
    case 1:
        func_ov008_02189c70(obj);
        break;
    case 2:
        obj->sub9a = 0;
        break;
    }
    switch (obj->sub9b) {
    case 0:
        func_ov008_0218af80(obj);
        break;
    case 1:
        func_ov008_02184754((char*)obj + 0x2a8);
        break;
    case 2:
        func_ov008_0218b084(obj);
        break;
    }
    return obj->fieldEb8;
}
