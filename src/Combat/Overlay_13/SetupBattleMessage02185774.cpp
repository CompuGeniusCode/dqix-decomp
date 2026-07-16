#include <globaldefs.h>

struct Container020e0310;
int GetGlobalField0x1c020421a0();
int GetFieldByKey020e0434(Container020e0310* c, int key);
extern "C" void func_0204500c(void*, const char*, int, int);

// USA: func_ov013_02185774
ARM void SetupBattleMessage02185774(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    int g = GetGlobalField0x1c020421a0();
    unsigned char tag = o[0x63c];
    if (tag == 4) {
        func_0204500c((void*)g, (const char*)GetFieldByKey020e0434((Container020e0310*)(o + 0x620), 0x3e8), 0, 0xe3);
    } else if (tag == 3) {
        func_0204500c((void*)g, (const char*)GetFieldByKey020e0434((Container020e0310*)(o + 0x620), 0x3e9), 0, 0xe3);
    } else if (tag == 2) {
        func_0204500c((void*)g, (const char*)GetFieldByKey020e0434((Container020e0310*)(o + 0x620), 0x3ea), 0, 0xe3);
    }
    *((unsigned char*)g + 0x1000 + 0x9b2) = 0;
    *(int*)(g + 0x998) = 1;
}
