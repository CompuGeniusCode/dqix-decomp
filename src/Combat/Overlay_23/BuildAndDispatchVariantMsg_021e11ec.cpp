#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Struct_021e12cc {
    int a;
    int b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
    unsigned char f;
};
void Init_021e12cc(struct Struct_021e12cc* s);
extern "C" void func_ov023_021e1410(void* a, struct Struct_021e12cc* s);

struct DataFA34_021e11ec {
    short count;
    short pad2;
    short* arr;
    int pad8;
    void* field0xc;
};
extern struct DataFA34_021e11ec data_ov023_021ffa34;

// USA: func_ov023_021e11ec
ARM int BuildAndDispatchVariantMsg_021e11ec(void* objRaw) {
    struct Variant02030b0c* obj = (struct Variant02030b0c*)objRaw;
    short v0 = (short)GetIntFromVariant02030b0c(obj);

    if (data_ov023_021ffa34.arr != 0 && data_ov023_021ffa34.count != 0) {
        int found = 0;
        short i;
        for (i = 0; i < data_ov023_021ffa34.count; i++) {
            if (v0 == data_ov023_021ffa34.arr[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) return 1;
    }

    struct Struct_021e12cc local;
    Init_021e12cc(&local);
    local.c = v0;
    local.d = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)obj + 8));
    local.e = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)obj + 0x10));
    local.rest = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)obj + 0x18));
    local.f = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)obj + 0x20));
    func_ov023_021e1410(data_ov023_021ffa34.field0xc, &local);
    return 1;
}
