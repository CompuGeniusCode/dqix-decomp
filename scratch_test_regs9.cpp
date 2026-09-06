#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" int Disp(void*, int);
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" void h(void*, int);
extern "C" int h2(int, int);
extern "C" int GetGlob(void);
extern "C" void AF(int,int,void*,int);
extern "C" void FC(void*, void*, int, int);
extern char sfx[];
struct D { char pad[8]; unsigned char* ptr; };
extern D dataX;
struct Ctx { char pad[0x998]; int f998; int f99c; };

extern "C" int frr9(void* param) {
    if (!Disp(param, 4)) return 0;
    char* battle = (char*)g1();
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        int* aPtr = (int*)(p + 0x5d00);
        if (h2(*aPtr, *(int*)(dataX.ptr + 0x10))) {
            char buf1[0x200];
            char buf0[0x220];
            memcpy(buf1, battle + 0x400, *(unsigned int*)(battle + 0x300));
            AF(GetGlob(), 0x1389, buf1, *(unsigned int*)(battle + 0x300));
            unsigned int slen = strlen(battle + 0x500);
            memcpy(buf0, battle + 0x500, slen);
            strcpy(buf0 + slen, sfx);
            Ctx* ctx = (Ctx*)(int)GetGlob();
            FC(ctx, buf0, 0, 0xe3);
            ctx->f998 = 1;
            ctx->f99c = 2;
        }
    }
    short v = *(short*)(dataX.ptr + 0x3a);
    for (int i = 0; i < v; i++);
    h(param, v + 100);
    return 0;
}
