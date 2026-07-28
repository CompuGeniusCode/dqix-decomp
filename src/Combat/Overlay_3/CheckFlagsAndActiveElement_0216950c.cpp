#include <globaldefs.h>

extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* a, int b);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

// USA: func_ov003_0216950c  (semantic: CheckFlagsAndActiveElement_0216950c)
extern "C" ARM int func_ov003_0216950c(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(obj + 0xe4, 0x14);
    int b = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x1);
    int c = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400);
    if ((b | c | a) != 0) {
        return 1;
    }
    return 0;
}
