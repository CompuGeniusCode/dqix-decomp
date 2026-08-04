#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;
extern int GetFieldByKey020e0434(Container020e0310*, int);
extern int AppendPaletteTag(char*, int);
extern int AppendXTag(char*, int);
extern int AppendString02042058(char*, const char*);
extern "C" int func_020420e8(void*, int);

struct StructA0205d5d0;
extern int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);

// USA: func_ov023_021d9a6c  (semantic: BuildElemPaletteTags_021d9a6c)
extern "C" ARM void func_ov023_021d9a6c(char* obj) {
    int flags = *(int*)(obj + 0xd9c);
    if (!(flags & 0x100)) return;

    if (*(signed char*)(obj + 0xc58) >= 0xb) {
        *(int*)(obj + 0xd9c) = flags & ~0x100;
        return;
    }

    unsigned char idx = *(unsigned char*)(obj + 0xda3);
    char* buf = *(char**)(obj + 0xf8);
    char* p = obj + idx;
    short base = (short)(idx * 100);

    short arr[7];
    arr[0] = (short)(base + 0x2710);
    arr[1] = (short)(*(unsigned char*)(p + 0xda4) + 0x2af8);
    arr[2] = (short)(base + 0x3a98 + *(unsigned char*)(p + 0xdac));
    arr[3] = (short)(*(unsigned char*)(p + 0xdae) + 0x3e80);
    arr[4] = (short)(base + 0x2ee0 + *(unsigned char*)(p + 0xda6));
    arr[5] = (short)(*(unsigned char*)(p + 0xdaa) + 0x36b0);
    arr[6] = (short)(*(unsigned char*)(p + 0xda8) + 0x32c8);

    memset(buf, 0, 0x960);

    int i;
    for (i = 0; i < *(signed char*)(obj + *(unsigned char*)(obj + 0xda3) + 0xda0); i++) {
        signed char val = *(signed char*)(obj + 0xc58);
        int tag = 15;
        if (i == val - 1) tag = 14;
        AppendPaletteTag(buf, tag);

        if (i < 7) {
            short v = arr[i];
            AppendXTag(buf, 0x32 - func_020420e8((void*)GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), v), 0));
            AppendString02042058(buf, (const char*)GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), v));
            AppendString02042058(buf, (const char*)GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), 0x4273));
        } else if (i == 7) {
            char* entry = (*(char***)(obj + 0xdb0))[*(unsigned char*)(obj + 0xda3)];
            if (*(signed char*)entry != 0) {
                AppendXTag(buf, 0x32 - func_020420e8(entry, 0));
                AppendString02042058(buf, entry);
            } else {
                AppendString02042058(buf, (const char*)GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), 0x4274));
            }
        }
    }

    TryApplyElemFields0205d5d0((StructA0205d5d0*)(obj + 0x1f8), 0, (int)buf, 0, 0);
    *(int*)(obj + 0xd9c) &= ~0x100;
}
