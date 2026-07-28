#include <globaldefs.h>

struct VtableObj0223c458 { unsigned char pad0[4]; int (*fn4)(void*, int); };

struct Obj0223c458 {
    unsigned char pad0[0x14];
    VtableObj0223c458* vtable14;
    unsigned char pad1[0x18 - 0x14 - 4];
    void* self18;
    void* field1c;
    int field20;
    int field24;
    int field28;
    short field2c;
    unsigned char pad2[0x2e - 0x2c - 2];
    unsigned char field2e;
    unsigned char field2f;
};

extern "C" void* func_ov031_0223bfa0(int a);
extern "C" int func_ov031_0223db7c(int a, int b, int c, int* out);
extern "C" int func_020b2054(int a, int b);
extern "C" int func_020b1ec0(void* obj, int offset, int b, int c, int flag);

extern void* data_ov031_02290d38;

// USA: func_ov031_0223c458  (semantic: AllocAndInitEntry_0223c458)
extern "C" ARM void* func_ov031_0223c458(int a0, int a1, int a2, int a3, void** out5, int a6) {
    unsigned char* g = (unsigned char*)data_ov031_02290d38;
    Obj0223c458* obj = (Obj0223c458*)func_ov031_0223bfa0(*(int*)(g + 0x670));

    obj->field2e = (unsigned char)a1;
    obj->field2f = (unsigned char)a2;

    int stackVal;
    obj->field28 = func_ov031_0223db7c(a0, a1 * a2, a3, &stackVal);
    obj->field2c = (short)stackVal;

    int r = func_020b2054(a1, a2);
    *out5 = (void*)r;

    int shifted = stackVal << 7;
    int off = (a0 == 1) ? 0x6600000 : 0x6400000;
    func_020b1ec0(obj, off + shifted, a1, a2, 4);

    obj->vtable14->fn4(obj, 0);

    void* g2 = data_ov031_02290d38;
    obj->self18 = obj;
    obj->field1c = (char*)g2 + a6 * 8;
    obj->field20 = 1;
    obj->field24 = 1;
    return obj;
}
