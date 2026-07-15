#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
int GetGlobalField0x1c020421a0();
extern "C" void func_02046608(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
extern int data_ov002_0216d26c;
int AppendLineTag02041cc0(char* dst, int a1);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
extern "C" void func_0205d0e0(void* obj, int val);

struct Struct_0205def8;
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int clear, int key);

struct BufOv0215c028 { char pad[0xbd0]; void* buf; };

// USA: func_ov002_0215c028
ARM void InitBattleTag0215c028(char* base) {
    func_ov002_0215be00(base, 0x28, 0x15, 0x13);
    int field = GetGlobalField0x1c020421a0();

    memset(((struct BufOv0215c028*)(base + 0x1000))->buf, 0, 0x960);
    func_02046608(field, 8, &data_ov002_0216d26c, ((struct BufOv0215c028*)(base + 0x1000))->buf, 0x100, 0, 0);
    AppendLineTag02041cc0((char*)((struct BufOv0215c028*)(base + 0x1000))->buf, 0x11);

    func_0205d304(base + 0xec8, ((struct BufOv0215c028*)(base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);
    func_0205d0e0(base + 0xec8, 4);
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)(base + 0xec8), 0, 0x28);
}
