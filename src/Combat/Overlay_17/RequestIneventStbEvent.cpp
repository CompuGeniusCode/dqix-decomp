#include <globaldefs.h>
#include "std_library_functions.h"

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
extern "C" int func_0201079c(char* obj);
extern "C" int func_020107d0(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);

extern char strIneventStb[0xc];

struct Obj021bba08 {
    char pad0[0xc];
    unsigned char f0xc;
    unsigned char f0xd;
    unsigned char f0xe;
    unsigned char f0xf;
    unsigned char f0x10;
    unsigned char f0x11;
    unsigned char f0x12;
    char pad1[0x16 - 0x13];
    short f0x16;
    char pad2[0x1a - 0x18];
    short f0x1a;
    char pad3[0x1e - 0x1c];
    char f0x1e[7];
    char pad4[0x3e - 0x25];
    char f0x3e[0xc];
    short f0x4a;
    short f0x4c;
    short f0x4e;
    short f0x50;
    short f0x52;
    char f0x54[0xc];
    short f0x60;
    char pad6[0x9c - 0x62];
    unsigned char f0x9c;
};

// Fills in the pending-event record so the next event comes from inevent.stb: func_021baedc wipes
// the record, the halfword at the front of the trigger becomes the entry to run at +0x1a, seven
// bytes from trigger+5 follow at +0x1e, and inevent.stb goes in the twelve-byte field at +0x3e -
// an archive member name, not a path, the ROM having data/event_lv5/inevent.gp2 whose members
// begin "inevent.". SetupEvluidaEventRequest requests evluida.stb the same way, past a guard and with
// an extra argument. The 100/200/300 at +0x4a are presumably delays or distances; not established.
extern "C" ARM void RequestIneventStbEvent(struct Obj021bba08* obj, unsigned char* arg1) {
    func_ov017_021baedc(obj, 1);
    obj->f0x9c = 1;

    struct BattleStruct* bs = GetBattleStruct();
    char* b = (char*)bs;
    obj->f0xc = (unsigned char)func_0201079c(b);
    obj->f0xe = (unsigned char)func_0201079c(b);
    obj->f0xd = (unsigned char)func_020107d0(b);
    obj->f0xf = (unsigned char)func_020107d0(b);

    obj->f0x16 = 3;
    obj->f0x10 = 1;
    obj->f0x11 = 0;

    obj->f0x1a = *(unsigned short*)arg1;
    memcpy(obj->f0x1e, arg1 + 5, 7);

    memcpy(obj->f0x3e, strIneventStb, 0xc);

    obj->f0x4a = 100;
    obj->f0x4c = 200;
    obj->f0x4e = 300;
    short v = 0x40;
    obj->f0x50 = v;
    obj->f0x52 = v - 0x41;

    obj->f0x12 = 0;
    memset(obj->f0x54, 0, 0xc);

    obj->f0x60 = 0;
}
