#include <globaldefs.h>

int GetField0_0205bafc(void* obj);
extern "C" void func_0205bb04(void* s, int n);
struct Struct_0205bcdc {
    int field0;
    char pad[0x2c];
    int field30;
};
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

// USA: func_0205d7a0
ARM void UpdateIndexPair0205d7a0(unsigned char* obj, int val) {
    int cur;
    if (obj[0x95]) {
        cur = GetField0_0205bafc(obj + 0x54);
    } else if (obj[0x94]) {
        cur = GetField0_0205bafc(obj + 0x4);
    }
    if (val < 0) {
        if (cur <= val) return;
    }
    if (obj[0x95]) {
        func_0205bb04(obj + 0x54, val);
    }
    if (obj[0x94] == 0) return;
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + 0x4), val);
}
