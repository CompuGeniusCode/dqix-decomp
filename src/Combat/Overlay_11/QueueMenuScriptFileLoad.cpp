#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* func_ov017_021b2164(void);
extern "C" int func_ov011_021849d8(void* p);
extern "C" void func_ov011_021849d0(void* p, int v);

extern const char strDataStr_02188b6c[];

struct S0218554c { int type; int field4; };

// Menu-script command: starts a background load of "data/<name>", the name coming from the command
// argument when it carries type 2, and parks the task id at +0x18c of the current menusys object --
// the global func_ov017_021b2200 zeroes when a menu closes. A second load is refused while that
// slot still holds an id, so it is one pending file per menu. Reached only as entry 13 of the ov011
// command table at data_ov011_021889a0; what kind of file it loads is not established, the format
// string being just the data root.
extern "C" ARM int QueueMenuScriptFileLoad(struct S0218554c* p) {
    int v = (p->type == 2) ? p->field4 : 0;
    if (v == 0) return 0;
    void* ctx = func_ov017_021b2164();
    if (func_ov011_021849d8(ctx) >= 0) return 0;
    int data4 = (int)BackgroundLoader::GetInstance();
    char buf[0x50];
    sprintf(buf, strDataStr_02188b6c, v);
    int r = ((BackgroundLoader*)(data4))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    func_ov011_021849d0(ctx, r);
    return 1;
}
