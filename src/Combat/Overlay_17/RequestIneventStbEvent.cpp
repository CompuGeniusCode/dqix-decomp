#include <globaldefs.h>
#include "std_library_functions.h"

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
extern "C" int func_0201079c(char* battle);
extern "C" int func_020107d0(char* battle);
extern "C" void func_ov017_021baedc(void* self, int partialReset);

extern char strIneventStb[0xc];

struct PendingEventRequest {
    char unknown0[0xc];
    unsigned char unknownc;
    unsigned char unknownd;
    unsigned char unknowne;
    unsigned char unknownf;
    unsigned char unknown10;
    unsigned char unknown11;
    unsigned char unknown12;
    char unknown13[0x16 - 0x13];
    short unknown16;
    char unknown18[0x1a - 0x18];
    short eventEntryId;
    char unknown1c[0x1e - 0x1c];
    char f0x1e[7];
    char unknown25[0x3e - 0x25];
    char scriptName[0xc];
    short unknown4a;
    short unknown4c;
    short unknown4e;
    short unknown50;
    short unknown52;
    char unknown54[0xc];
    short unknown60;
    char unknown62[0x9c - 0x62];
    unsigned char unknown9c;
};

// Fills in the pending-event record so the next event comes from inevent.stb: func_ov017_021baedc
// wipes the record first, memsetting +0xc through +0x73 outright, then the halfword at the front of
// the trigger becomes the entry to run at +0x1a, seven bytes from trigger+5 follow at +0x1e, and
// inevent.stb goes in the twelve-byte field at +0x3e - an archive member name, not the path, the
// ROM having data/event_lv5/inevent.gp2 whose members begin "inevent.". The four bytes at +0xc
// through +0xf take the battle struct word at +0x5cb0 twice and the word at +0x5cb4 twice; what
// those two hold is not established, only that func_02010774 and func_020107a8 mirror them into
// bytes 0 and 1 of the 0x1c-byte record they keep. SetupEvluidaEventRequest requests evluida.stb
// the same way, past its own guard and with one extra argument; it stores 1 at +0x16 where this
// stores 3, and 0x10 at +0x50 where this stores 0x40, so +0x52 comes out -1 in both. The 100/200/300
// at +0x4a are presumably delays or distances; not established.
extern "C" ARM void RequestIneventStbEvent(struct PendingEventRequest* request, unsigned char* trigger) {
    func_ov017_021baedc(request, 1);
    request->unknown9c = 1;

    struct BattleStruct* bs = GetBattleStruct();
    char* battle = (char*)bs;
    request->unknownc = (unsigned char)func_0201079c(battle);
    request->unknowne = (unsigned char)func_0201079c(battle);
    request->unknownd = (unsigned char)func_020107d0(battle);
    request->unknownf = (unsigned char)func_020107d0(battle);

    request->unknown16 = 3;
    request->unknown10 = 1;
    request->unknown11 = 0;

    request->eventEntryId = *(unsigned short*)trigger;
    memcpy(request->f0x1e, trigger + 5, 7);

    memcpy(request->scriptName, strIneventStb, 0xc);

    request->unknown4a = 100;
    request->unknown4c = 200;
    request->unknown4e = 300;
    short unknown50Value = 0x40;
    request->unknown50 = unknown50Value;
    request->unknown52 = unknown50Value - 0x41;

    request->unknown12 = 0;
    memset(request->unknown54, 0, 0xc);

    request->unknown60 = 0;
}
