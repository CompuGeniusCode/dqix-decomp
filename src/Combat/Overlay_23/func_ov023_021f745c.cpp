#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ObjBase021f6ed8;
extern "C" ARM void func_ov023_021f6ed8(struct ObjBase021f6ed8* obj);

struct List0204af64 {
    char pad0[0x1c];
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
void ResetList0204af64(struct List0204af64* obj);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);
extern "C" void func_0204b5b4(void*, int);

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8*, int, int);

extern "C" void* func_ov011_021845f8(void* ctx, int v);

struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);

struct Obj021f7a08;
extern "C" ARM void func_ov023_021f7a08(struct Obj021f7a08* obj, void* keyObj);

// USA: func_ov023_021f745c
extern "C" ARM int func_ov023_021f745c(char* obj, void* arg1, int arg2, int arg3, int p5, int p6, int p7, int p8, int p9) {
    func_ov023_021f6ed8((struct ObjBase021f6ed8*)obj);
    *(short*)(obj + 0x4) = 2;
    *(void**)(obj + 0x20) = arg1;
    *(short*)(obj + 0x6) = (short)arg2;
    *(short*)(obj + 0x8) = (short)arg3;
    *(short*)(obj + 0xa) = 0;
    *(int*)(obj + 0x24) = p5;
    *(int*)(obj + 0x10) = p6;
    *(int*)(obj + 0x48) = 0;
    ResetList0204af64((struct List0204af64*)(obj + 0x28));
    SetWord0x18ClearByte0x1f((unsigned char*)(obj + 0x28), 0);

    struct List0204af64* list = (struct List0204af64*)(obj + 0x28);
    list->b1c_lo = (unsigned char)p7;
    list->b1c_hi = (unsigned char)p8;

    func_0204b5b4(obj + 0x28, p9);
    DispatchViaTable0204b5e8((struct Obj0204b5e8*)(obj + 0x28), 0, 0);

    void* result = func_ov011_021845f8(arg1, *(unsigned short*)(obj + 0x8));
    if (result == 0) return 0;

    AllocateAndClearBuffer0204b12c((struct AllocTarget0204b12c*)(obj + 0x28), (SafeAllocator*)((char*)result + 4));
    func_ov023_021f7a08((struct Obj021f7a08*)obj, arg1);
    *(short*)(obj + 0x50) = 0;
    *(short*)(obj + 0x52) = 0;
    return 1;
}
