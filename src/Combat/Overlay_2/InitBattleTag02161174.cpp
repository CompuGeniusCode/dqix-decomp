#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_02161234(void* base, void* dst, int flag);

struct S020466c8;
void SetField0x38(struct S020466c8* p, int v);

extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);

struct FieldBB8Ov02161174 { char pad[0xbb8]; int field; };
struct Field998Ov02161174 { char pad[0x998]; int field998; };
struct Field9caOv02161174 { char pad[0x9ca]; unsigned char field9ca; };
struct BufOv02161174 { char pad[0xbd0]; void* buf; };

// USA: func_ov002_02161174
ARM void InitBattleTag02161174(char* base) {
    int field = GetGlobalField0x1c020421a0();

    func_ov002_0215be00(base, ((struct FieldBB8Ov02161174*)(base + 0x1000))->field & 0xff, 0, 0xf);

    if (*(unsigned char*)(base + 0x1000 + 0xc31) != 0) {
        memcpy(((struct BufOv02161174*)(base + 0x1000))->buf, *(void**)(base + 0x1000 + 0xbd4), 0x960);
    } else {
        memset(((struct BufOv02161174*)(base + 0x1000))->buf, 0, 0x960);
        func_ov002_02161234(base, ((struct BufOv02161174*)(base + 0x1000))->buf, 0);
    }

    SetField0x38((struct S020466c8*)field, *(int*)(*(int*)base + 0x10));
    func_0204500c((void*)field, ((struct BufOv02161174*)(base + 0x1000))->buf, 0, 0xe3);
    ((struct Field998Ov02161174*)field)->field998 = 1;

    if (*(short*)(base + 0x1c28) == 0x232b) {
        ((struct Field9caOv02161174*)(field + 0x1000))->field9ca = 0;
    }
}
