#include <globaldefs.h>
#include "std_library_functions.h"

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
extern "C" int func_0201079c(char* obj);
extern "C" int func_020107d0(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);

extern char strEvluidaStb[0xc];
extern char strF12ev3D[7];

struct Obj021bbae4 {
    unsigned char pad0[2];
    unsigned char byte2;
    char pad1[0xc - 3];
    unsigned char f0xc;
    unsigned char f0xd;
    unsigned char f0xe;
    unsigned char f0xf;
    unsigned char f0x10;
    unsigned char f0x11;
    unsigned char f0x12;
    unsigned char f0x13;
    char pad2[0x16 - 0x14];
    short f0x16;
    char pad3[0x1a - 0x18];
    short f0x1a;
    char pad4[0x1e - 0x1c];
    char f0x1e[7];
    char pad5[0x3e - 0x25];
    char f0x3e[0xc];
    short f0x4a;
    short f0x4c;
    short f0x4e;
    short f0x50;
    short f0x52;
    char f0x54[0xc];
    short f0x60;
    char f0x62[7];
    char pad7[0xcc - 0x69];
    unsigned char f0xcc;
};

// Fills in an event-scene request and stamps it with the script name "evluida.stb" and the scene
// tag "f12ev3D"; the caller in ov003 then appends the record to the pending-event list. It bails
// out when the byte at +0x2 is already set, presumably so a request cannot be queued twice.
// RequestIneventStbEvent is the same builder for "inevent.stb", differing at +0x16 and in a few other
// fields. evluida is presumably the Luida's Bar event - data/evspt_lv5/evluida.gp2 holds both the
// .stb and LUIDA_ - but the expansion is not established, and nothing ties f12ev3D to the F12 map.
extern "C" ARM void SetupEvluidaEventRequest(struct Obj021bbae4* self, unsigned char* arg1, unsigned char arg2) {
    if (self->byte2 != 0) {
        return;
    }
    func_ov017_021baedc(self, 1);
    self->f0xcc = arg2;

    struct BattleStruct* bs = GetBattleStruct();
    char* b = (char*)bs;
    self->f0xc = (unsigned char)func_0201079c(b);
    self->f0xe = (unsigned char)func_0201079c(b);
    self->f0xd = (unsigned char)func_020107d0(b);
    self->f0xf = (unsigned char)func_020107d0(b);

    self->f0x16 = 1;
    self->f0x10 = 1;
    self->f0x11 = 0;

    self->f0x1a = *(unsigned short*)arg1;
    memcpy(self->f0x1e, arg1 + 5, 7);

    memcpy(self->f0x3e, strEvluidaStb, 0xc);

    self->f0x4a = 100;
    self->f0x4c = 200;
    self->f0x4e = 300;
    short v = 0x10;
    self->f0x50 = v;
    self->f0x52 = v - 0x11;

    self->f0x12 = 0;
    memset(self->f0x54, 0, 0xc);

    self->f0x60 = 0;
    self->f0x13 = 1;
    memcpy(self->f0x62, strF12ev3D, 7);
}
