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

extern "C" int frr10(void* param) {
    if (!Disp(param, 4)) return 0;
    char* battle = (char*)g1();
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        int* aPtr = (int*)(p + 0x5d00);
        unsigned char* ptr = dataX.ptr;
        int a = *aPtr;
        int b = *(int*)(ptr + 0x10);
        if (h2(a, b)) {
            char buf1[0x200];
            char buf0[0x220];
            unsigned int len = *(unsigned int*)(battle + 0x300);
            memcpy(buf1, battle + 0x400, len);
            int g = GetGlob();
            AF(g, 0x1389, buf1, len);
            char* s = battle + 0x500;
            unsigned int slen = strlen(s);
            memcpy(buf0, s, slen);
            strcpy(buf0 + slen, sfx);
            void* ctx = (void*)GetGlob();
            FC(ctx, buf0, 0, 0xe3);
        }
    }
    short v = *(short*)(dataX.ptr + 0x3a);
    for (int i = 0; i < v; i++);
    h(param, v + 100);
    return 0;
}
