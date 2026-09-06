#include <globaldefs.h>

void* GetElementAtIndex_02160bd0_02160bd0(void* unused, int index);
extern "C" void func_ov003_02167a5c(void* p, int type, int val);

// USA: func_ov003_02161438
ARM void ApplyElementEffect02161438(void* obj) {
    char* p = (char*)obj + 0x400;
    short v = *(short*)(p + 0x8c);
    signed char b = *(signed char*)(p + 0x9f);
    int idx = (v - 0x15) + (b << 2);
    int val = -1;
    void* e = GetElementAtIndex_02160bd0_02160bd0(obj, idx);
    if (e != NULL) {
        signed char c = *(signed char*)e;
        val = (c << 26) >> 26;
    }
    func_ov003_02167a5c(*(void**)((char*)obj + 0x318), 6, val);
}
