#include <globaldefs.h>

struct Container020e0310;
int GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_0204500c(void*, const void*, int, int);

// USA: func_ov017_021a933c
#pragma optimize_for_size off
ARM void SetFieldMessageAndFlag_021a933c(void* obj, int key) {
    unsigned char* o = (unsigned char*)obj;
    int g = GetGlobalField0x1c020421a0();
    if (key <= 0xc7 && key >= 0x64) {
        if (*(int*)(o + 0x14) == 1) key += 0x64;
    }
    func_0204500c((void*)g, (const void*)GetFieldByKey020e0434((Container020e0310*)(o + 0x278), (short)key), 0, 0xe3);

    if (key > 0x12b) goto writeZero;
    if (key < 0x64) goto writeZero;
    *((unsigned char*)g + 0x1000 + 0x9b2) = 1;
    goto afterFlag;
writeZero:
    *((unsigned char*)g + 0x1000 + 0x9b2) = 0;
afterFlag:;

    if (key > 0x12b) return;
    if (key < 0x64) return;
    *(int*)(g + 0x99c) = (*(int*)(o + 0x14) == 0) ? 2 : 1;
}
