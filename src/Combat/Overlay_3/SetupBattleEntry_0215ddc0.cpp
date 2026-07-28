#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
void SetupFieldAndFormat_0215de6c(char* base, void* buf);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

// USA: func_ov003_0215ddc0  (semantic: SetupBattleEntry_0215ddc0)
extern "C" ARM void func_ov003_0215ddc0(char* base) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + 0x98), 0, 2);

    *(unsigned short*)(base + 0x100 + 0x38) = 0xb;
    *(unsigned short*)(base + 0x100 + 0x3a) = 2;
    *(unsigned short*)(base + 0x100 + 0x3c) = 0x14;
    *(unsigned short*)(base + 0x100 + 0x3e) = 0;
    *(unsigned short*)(base + 0x100 + 0x40) = 0x10;
    *(unsigned short*)(base + 0x100 + 0x42) = 2;
    *(unsigned short*)(base + 0x100 + 0x44) = 8;
    *(unsigned short*)(base + 0x100 + 0x46) = 8;

    *(unsigned char*)(base + 0x14f) = 8;
    *(unsigned char*)(base + 0x149) = 0;
    *(unsigned char*)(base + 0x14d) = 1;

    memset(*(void**)(base + 0x7c), 0, 0x960);
    SetupFieldAndFormat_0215de6c(base, *(void**)(base + 0x7c));

    func_0205d304(base + 0x98, *(void**)(base + 0x7c), 0, 0, 0, 1, 0, 0);
}
