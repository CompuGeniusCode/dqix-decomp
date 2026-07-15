#include <globaldefs.h>

extern "C" void* func_ov000_02153710(void*);
extern "C" int func_ov000_02159dbc(void*, int);

// USA: func_ov000_02159e60
ARM signed char GetFieldOrFallback02159e60(void* obj, int mode) {
    int inRange = (mode >= 0 && mode <= 3);
    int v;
    if (inRange) {
        char* base = (char*)func_ov000_02153710(obj);
        int idx = *(int*)(base + 0x950);
        v = *(unsigned short*)(base + idx * 2 + 0x16c);
    } else {
        v = func_ov000_02159dbc(obj, mode);
    }
    return (signed char)v;
}
