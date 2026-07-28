#include <globaldefs.h>

struct Container020e0310;
int GetGlobalField0x1c020421a0(void);
int GetFieldByKey020e0434(struct Container020e0310*, int);
extern "C" void func_0204500c(void*, const char*, int, int);

// USA: func_ov017_021a933c  (semantic: AppendMessageAndUpdateStatus_021a933c)
extern "C" ARM void func_ov017_021a933c(void* obj, int key) {
    char* o = (char*)obj;
    int g = GetGlobalField0x1c020421a0();
    if (key <= 0xc7 && key >= 0x64) {
        if (*(int*)(o + 0x14) == 1) key += 0x64;
    }
    func_0204500c((void*)g, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(o + 0x278), (short)key), 0, 0xe3);
    if (key <= 0x12b && key >= 0x64) {
        *((unsigned char*)g + 0x1000 + 0x9b2) = 1;
    } else {
        *((unsigned char*)g + 0x1000 + 0x9b2) = 0;
    }
    if (key > 0x12b || key < 0x64) return;
    if (*(int*)(o + 0x14) == 0) {
        *(int*)(g + 0x99c) = 2;
    } else {
        *(int*)(g + 0x99c) = 1;
    }
}
