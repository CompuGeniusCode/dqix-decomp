#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct InitStruct02075cdcStruct;
extern "C" void func_02075cdc(struct InitStruct02075cdcStruct* s);
extern "C" void* GetOamManager(void);
extern "C" void* GetSubScreenOamBuffer(void);
struct StructDE234_020de234;
extern "C" unsigned short func_020de234(struct StructDE234_020de234* p, int preferMid);

extern char strDataAniDChrNumSpr_02160360[];

// Initialises the icon slot at self+0x3b8 and starts the background load of the icon for the record
// it is given. The path is data/ani/d_<c><nnn>.spr: the letter is the low byte of the record's
// 12-bit field at +0x10, the number comes from func_020de234, and 999 is that
// field's "none" value - no d_*999.spr exists. All 1021 of these files are 24x24 4bpp, so they are
// menu icons. Calling the record an item record is inferred from its other readers - main, ov005
// equipment, ov015 charaview, ov017 and ov023 sub_menu - not proven here.
extern "C" ARM void SetUpItemIconSprite(char* self, struct StructDE234_020de234* info) {
    if (info == NULL) {
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    func_02075cdc((struct InitStruct02075cdcStruct*)(self + 0x3b8));
    *(int*)(self + 0x3f4) = 5;
    *(unsigned char*)(self + 0x416) = 1;

    GetOamManager();
    void* p = GetSubScreenOamBuffer();
    *(char**)(self + 0x3cc) = (char*)p + 0x1b8;

    *(int*)(self + 0x3f0) = 0x10000;
    *(int*)(self + 0x3f8) = 0;

    unsigned short val = func_020de234(info, 0);

    unsigned int raw10 = *(unsigned int*)((char*)info + 0x10);
    int percent = (raw10 << 4) >> 0x18;

    char buf[0x40];
    sprintf(buf, strDataAniDChrNumSpr_02160360, percent, val);

    int r = loader->QueueLoadFile((const char*)buf, (SafeAllocator*)0);
    *(int*)(self + 0x428) = r;
}
