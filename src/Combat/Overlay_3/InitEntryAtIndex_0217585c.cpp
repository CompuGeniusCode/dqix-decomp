#include <globaldefs.h>

extern "C" void func_0205ac40(void*, void*, int);

// USA: func_ov003_0217585c
ARM void InitEntryAtIndex_0217585c(void* obj, int a, int b, int idx, unsigned char c) {
    char* entry = *(char**)((char*)obj + 0x830) + idx * 0x28;
    *(unsigned char*)(entry + 0x22) = c;
    *(int*)(entry + 0x14) = a << 12;
    *(int*)(entry + 0x18) = b << 12;
    func_0205ac40((char*)obj + 0x7d8, entry, b << 12);
}
