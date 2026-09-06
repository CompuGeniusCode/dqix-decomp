#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021dbfd0(void*, void*);
void SetFlagAndData_021dbfa8(void* obj, int val);
void ClearFields_021e20c0(void* p);
void ResetList0204af64(void* obj);
extern "C" void func_0204c684(void*);
extern "C" void func_0207f84c(void*);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198*);

extern int data_ov006_0215ff7c[];

struct Obj02154348 {
    unsigned char pad0[0x180];
    void* f180;
    void* f184;
    void* f188;
    unsigned char pad1[0x1c4 - 0x18c];
    void* f1c4;
    void* f1c8;
    void* f1cc;
    void* f1d0;
    void* f1d4;
    unsigned char pad2[0x1e0 - 0x1d8];
    void* f1e0;
    unsigned char pad3[0x1280 - 0x1e4];
    SafeAllocator* f1280;
    SafeAllocator* f1284;
};

// USA: func_ov006_02154348
ARM void InitAllocations02154348(struct Obj02154348* obj, SafeAllocator* alloc, int arg3) {
    unsigned char i;

    obj->f180 = alloc->Allocate(0x78);
    obj->f184 = alloc->Allocate(0x14);
    obj->f188 = alloc->Allocate(0x14);
    obj->f1c4 = alloc->Allocate(0x80);
    obj->f1c8 = alloc->Allocate(0x4c);
    obj->f1cc = alloc->Allocate(0x40);
    obj->f1d0 = alloc->Allocate(0xe0);
    obj->f1d4 = alloc->Allocate(0x40);
    obj->f1e0 = alloc->Allocate(0x2a8);

    ((SafeAllocator*)obj->f184)->CreateTypeA(alloc->Allocate(0x258), 0x258);
    ((SafeAllocator*)obj->f188)->CreateTypeA(alloc->Allocate(0x258), 0x258);
    ((SafeAllocator*)obj->f184)->Reset();
    ((SafeAllocator*)obj->f188)->Reset();

    obj->f1280 = (SafeAllocator*)alloc->Allocate(0x14);
    obj->f1284 = (SafeAllocator*)alloc->Allocate(0x14);
    obj->f1280->CreateTypeA(alloc->Allocate(0x1e00), 0x1e00);
    obj->f1280->Reset();
    obj->f1284->CreateTypeA(alloc->Allocate(0x80), 0x80);
    obj->f1284->Reset();

    func_ov023_021dbfd0((char*)obj + 0xae4, obj->f1280);
    SetFlagAndData_021dbfa8((char*)obj + 0xae4, arg3);

    for (i = 0; i < 6; i++) {
        int sz = data_ov006_0215ff7c[i];
        void* buf = alloc->Allocate(sz);
        SafeAllocator* sub = (SafeAllocator*)((char*)obj->f180 + i * 0x14);
        sub->CreateTypeA(buf, sz);
        sub->Reset();
    }

    for (i = 0; i < 4; i++) {
        void* buf = alloc->Allocate(0x280);
        SafeAllocator* sub = (SafeAllocator*)((char*)obj + 0x284 + 0x800 + i * 0x14);
        sub->CreateTypeA(buf, 0x280);
        sub->Reset();
    }

    *(unsigned char*)obj->f1c4 = 0;
    ClearFields_021e20c0(obj->f1c8);

    for (i = 0; i < 2; i++) {
        ResetList0204af64((char*)obj->f1cc + i * 0x20);
    }
    for (i = 0; i < 1; i++) {
        func_0204c684((char*)obj->f1d0 + i * 0xe0);
    }
    func_0207f84c(obj->f1d4);
    for (i = 0; i < 0x11; i++) {
        Init0205a198((struct Struct0205a198*)((char*)obj->f1e0 + i * 0x28));
    }
}
