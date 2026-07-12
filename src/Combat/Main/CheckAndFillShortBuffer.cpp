#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(Variant02030b0c*);
extern "C" int func_ov017_0218b5b0(void);

struct Globals0208e444 {
    char pad[0xc];
    unsigned short* buf;
};
extern struct Globals0208e444 data_02108fe4;

// USA: func_0208e444
ARM int CheckAndFillShortBuffer(char* v) {
    unsigned char* p = (unsigned char*)GetBattleStruct() + 0x5000;
    unsigned char expected = p[0xcda];
    unsigned char got = (unsigned char)GetIntFromVariant02030b0c((Variant02030b0c*)v);
    v += 8;
    if (expected == got) {
        SafeAllocator* alloc = (SafeAllocator*)(func_ov017_0218b5b0() + 0x1a0);
        int buf = (int)alloc->Allocate(0x20);
        data_02108fe4.buf = (unsigned short*)buf;
        for (int i = 0; i < 0x10; i++) {
            unsigned short val = (unsigned short)GetIntFromVariant02030b0c((Variant02030b0c*)v);
            v += 8;
            *(unsigned short*)buf = val;
            buf += 2;
        }
    }
    return 1;
}
