#include <globaldefs.h>

void CopyFrom027ffcf4(void* dst);
extern "C" int func_0202d788(unsigned short);
void SetField0x48UnlessState9Or10(int arg);

extern char data_021015a0;

// USA: func_0202d6c8
ARM int InitBattleSeedAndDispatch_0202d6c8(void) {
    unsigned short v[3];
    CopyFrom027ffcf4(v);
    int* p = (int*)0x27ffc3c;
    unsigned short v0 = v[0];
    int val = *p;
    unsigned short v1 = v[1];
    int seed = v0 + val;
    unsigned short v2 = v[2];
    seed = v1 + seed;
    seed = v2 + seed;
    *(int*)(&data_021015a0 + 0x20) = seed * 0x10dcd + 0x39 + 0x3000;
    *(unsigned short*)(&data_021015a0 + 0x2) = 0;
    *(unsigned short*)(&data_021015a0 + 0x6) = 0x65;
    *(int*)(&data_021015a0 + 0x10) = 3;
    int r = func_0202d788(1);
    if (r == 0x18) {
        SetField0x48UnlessState9Or10(0x18);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0;
    }
    if (r == 2) {
        return 1;
    }
    SetField0x48UnlessState9Or10(r);
    *(int*)(&data_021015a0 + 0x10) = 9;
    return 0;
}
