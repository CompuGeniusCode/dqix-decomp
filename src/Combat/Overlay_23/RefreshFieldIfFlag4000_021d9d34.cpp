#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310*, int);
int AppendString02042058(char*, const char*);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);

// USA: func_ov023_021d9d34
ARM void RefreshFieldIfFlag4000_021d9d34(char* obj) {
    if (!(*(int*)(obj + 0xd9c) & 0x4000)) return;

    char* buf = *(char**)(obj + 0xf8);
    memset(buf, 0, 0x960);

    int fieldVal = GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), 0x4274);
    AppendString02042058(buf, (const char*)fieldVal);

    TryApplyElemFields0205d5d0((StructA0205d5d0*)(obj + 0x2b4), 2, (int)buf, 1, 0);

    *(int*)(obj + 0xd9c) &= ~0x4000;
}
