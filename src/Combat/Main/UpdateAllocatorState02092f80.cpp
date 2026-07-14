#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

int GetData02104304Field4();

int CallFunc0202fa38Mode2(int a, int b, int c, int d);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020301c8(int a, int b);
    void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
}

extern int data_020f1368;
extern int data_020f1382;

struct Obj02092f80 {
    unsigned char pad0[0x2c];
    int field_2c;
    unsigned char pad2c[0x34 - 0x30];
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char field_37;
};

// USA: func_02092f80
ARM void UpdateAllocatorState02092f80(Obj02092f80* obj) {
    int ctx = GetData02104304Field4();
    unsigned char state = obj->field_35;

    if (state == 0) {
        obj->field_2c = CallFunc0202fa38Mode2(ctx, (int)&data_020f1368, (int)&data_020f1382, 0);
        obj->field_35++;
    } else if (state == 1) {
        if (func_0202fdd0(ctx, obj->field_2c)) {
            int out1, out2;
            GetListEntryValues0202fec8((struct List0202fec8*)ctx, obj->field_2c, &out1, &out2);
            ((SafeAllocator*)obj)->Reset();
            func_020dfec0((char*)obj + 0x14, obj, (void*)out1, (unsigned int)out2);
            func_020301c8(ctx, obj->field_2c);
            obj->field_2c = -1;
            obj->field_35++;
        }
    } else if (state == 2) {
        obj->field_34 = 3;
        obj->field_35 = 0;
        if (obj->field_37 & 0x1) obj->field_34 = 1;
        if (!(obj->field_37 & 0x8)) obj->field_37 |= 0x4;
        obj->field_36 = 0;
    }
}
