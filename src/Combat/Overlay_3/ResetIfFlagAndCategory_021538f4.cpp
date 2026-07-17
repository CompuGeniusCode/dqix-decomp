#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int, int);

// USA: func_ov003_021538f4
ARM void ResetIfFlagAndCategory_021538f4(void* obj, int cat) {
    unsigned char* o = (unsigned char*)obj;
    if (*(unsigned char*)(o + 0x5a) == 0) return;
    signed char b = *(signed char*)(o + 0x59);
    int ok = 0;
    if (b < 0) goto check;
    if (b <= 3) ok = 1;
check:
    if (!ok) return;
    if (cat <= 0) return;
    if (cat >= 0xd) return;
    if (*(int*)(o + 0x14) == cat) return;

    int listPtr = GetData02104304Field4();
    int f50 = *(int*)(o + 0x50);
    if (f50 >= 0) func_020301c8(listPtr, f50);
    int f54 = *(int*)(o + 0x54);
    if (f54 >= 0) func_020301c8(listPtr, f54);
    *(int*)(o + 0x50) = -1;
    *(int*)(o + 0x54) = -1;
    *(int*)(o + 0x14) = cat;
    *(unsigned char*)(o + 0x5b) = 0;
    *(unsigned char*)(o + 0x5c) = 0;
    *(unsigned char*)(o + 0x5d) |= 1;
}
