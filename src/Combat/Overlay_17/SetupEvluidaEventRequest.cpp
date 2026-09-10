#include <globaldefs.h>
#include "std_library_functions.h"

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
extern "C" int func_0201079c(char* battleStruct);
extern "C" int func_020107d0(char* battleStruct);
extern "C" void func_ov017_021baedc(void* self, int partialReset);

extern char strEvluidaStb[0xc];
extern char strF12ev3D[7];

struct EventRequest {
    unsigned char unknown0[2];
    unsigned char byte2;
    char unknown3[0xc - 3];
    unsigned char f0xc;
    unsigned char f0xd;
    unsigned char f0xe;
    unsigned char f0xf;
    unsigned char f0x10;
    unsigned char f0x11;
    unsigned char f0x12;
    unsigned char f0x13;
    char unknown14[0x16 - 0x14];
    short f0x16;
    char unknown18[0x1a - 0x18];
    short entryId;
    char unknown1c[0x1e - 0x1c];
    char f0x1e[7];
    char unknown25[0x3e - 0x25];
    char scriptName[0xc];
    short f0x4a;
    short f0x4c;
    short f0x4e;
    short f0x50;
    short f0x52;
    char f0x54[0xc];
    short f0x60;
    char sceneTag[7];
    char unknown69[0xcc - 0x69];
    unsigned char f0xcc;
};

// Fills in an event-scene request and stamps it with the script name "evluida.stb" and the scene
// tag "f12ev3D"; the caller in ov003 then appends the record to the pending-event list. It bails
// out when the byte at +0x2 is already set, presumably so a request cannot be queued twice.
// RequestIneventStbEvent is the same builder for "inevent.stb", differing at +0x16 and in a few other
// fields. evluida is presumably the Luida's Bar event - data/evspt_lv5/evluida.gp2 holds both the
// .stb and LUIDA_ - but the expansion is not established, and nothing ties f12ev3D to the F12 map.
// func_ov017_021baedc wipes the record, and with its argument zero would also clear +0x105 and
// +0x11c; both builders pass 1. The short at +0x50 is 0x10 here against 0x40 there, and +0x52 is
// that value less one more than itself either way, so it lands at -1 in both; what either holds is
// not established, and neither is the byte at +0xcc that only this builder writes.
extern "C" ARM void SetupEvluidaEventRequest(struct EventRequest* self, unsigned char* trigger, unsigned char unknownccValue) {
    if (self->byte2 != 0) {
        return;
    }
    func_ov017_021baedc(self, 1);
    self->f0xcc = unknownccValue;

    struct BattleStruct* bs = GetBattleStruct();
    char* battle = (char*)bs;
    self->f0xc = (unsigned char)func_0201079c(battle);
    self->f0xe = (unsigned char)func_0201079c(battle);
    self->f0xd = (unsigned char)func_020107d0(battle);
    self->f0xf = (unsigned char)func_020107d0(battle);

    self->f0x16 = 1;
    self->f0x10 = 1;
    self->f0x11 = 0;

    self->entryId = *(unsigned short*)trigger;
    memcpy(self->f0x1e, trigger + 5, 7);

    memcpy(self->scriptName, strEvluidaStb, 0xc);

    self->f0x4a = 100;
    self->f0x4c = 200;
    self->f0x4e = 300;
    short unknown50Value = 0x10;
    self->f0x50 = unknown50Value;
    self->f0x52 = unknown50Value - 0x11;

    self->f0x12 = 0;
    memset(self->f0x54, 0, 0xc);

    self->f0x60 = 0;
    self->f0x13 = 1;
    memcpy(self->sceneTag, strF12ev3D, 7);
}
