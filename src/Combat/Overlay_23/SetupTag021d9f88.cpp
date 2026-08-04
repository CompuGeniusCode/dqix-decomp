#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

extern "C" void func_0205bb04(void* s, int n);

struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);

extern "C" void func_ov023_021da100(char* obj, char* dst, int flag);

extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

// USA: func_ov023_021d9f88  (semantic: SetupTag021d9f88)
extern "C" ARM void func_ov023_021d9f88(void* objRaw) {
    char* obj = (char*)objRaw;
    obj[0xd84] = 0;
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x2b8), 1, 2, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x308), 1, 2, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x2b8), 2);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x308), 2);
    *(int*)(obj + 0x2bc) = 1;
    *(int*)(obj + 0x30c) = 1;

    signed char cursor = *(signed char*)(obj + 0xd84);
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + 0x2b8), cursor);
    func_0205bb04(obj + 0x308, cursor);

    obj[0x348] = 1;
    obj[0x349] = 1;

    int val = 0x10;
    struct Struct0200fb08* bs = (struct Struct0200fb08*)GetBattleStruct();
    unsigned char norm = NormalizeField5_0200fb08(bs);
    switch (norm) {
        case 2: val = 0xe; break;
        case 4: val = 0x15; break;
        case 3: val = 0xa; break;
        case 5: val = 0x15; break;
        default: break;
    }

    char* tag = obj + 0x2b4;
    *(unsigned short*)(tag + 0xa0) = 6;
    *(unsigned short*)(tag + 0xa2) = 5;
    *(unsigned short*)(tag + 0xa4) = 0x1a;
    *(unsigned short*)(tag + 0xa6) = 0xa;
    *(unsigned short*)(tag + 0xa8) = val;
    *(unsigned short*)(tag + 0xaa) = 0;
    *(unsigned short*)(tag + 0xac) = 0xc;
    *(unsigned short*)(tag + 0xae) = 0x10;
    tag[0xb1] = 1;
    tag[0xb7] = 0xc;
    tag[0xb5] = 1;
    tag[0xb6] = 0;

    void* buf = *(void**)(obj + 0xf8);
    memset(buf, 0, 0x960);
    func_ov023_021da100(obj, (char*)buf, 0);
    func_0205d304(tag, buf, 0, 0, 0, 0, 0, 1);
}
