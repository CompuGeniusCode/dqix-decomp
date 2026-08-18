#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned char data_02114e54;

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

extern "C" void func_ov023_021da100(char* obj, char* dst, int flag);

struct Sub2b8 { char pad[0x30]; int v; };
struct Outer021da1dc { char pad[0x2b8]; Sub2b8 sub; };

// USA: func_ov023_021da1dc
extern "C" ARM void func_ov023_021da1dc(char* objRaw) {
    Outer021da1dc* obj = (Outer021da1dc*)objRaw;
    unsigned char b = *(unsigned char*)(objRaw + 0xd85);
    if (b == 0) return;

    int flag = 0;
    if (b == 2) {
        if (*(unsigned char*)((char*)&data_02114e54 + 0x5f) != 0 &&
            *(unsigned short*)((char*)&data_02114e54 + 0x24) != 0) {
            int v = obj->sub.v;
            if (v < 0) return;
            flag = 1;
        }
    }

    char* buf = *(char**)(objRaw + 0xf8);
    memset(buf, 0, 0x960);
    func_ov023_021da100(objRaw, buf, flag);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(objRaw + 0x2b4), 1, (int)buf, 0, 1);
}
