#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);

struct Container020e0310;
extern int GetFieldByKey020e0434(struct Container020e0310*, int);

extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

// USA: func_ov023_021d99a4  (semantic: SetupTag021d99a4)
extern "C" ARM void func_ov023_021d99a4(void* objRaw) {
    char* obj = (char*)objRaw;
    struct Struct0200fb08* bs = (struct Struct0200fb08*)GetBattleStruct();
    int fieldA4 = 0x18;
    int norm = NormalizeField5_0200fb08(bs);
    if (norm == 4) fieldA4 = 0x19;
    char* tag = obj + 0x1f8;
    *(unsigned short*)(tag + 0xa0) = 7;
    *(unsigned short*)(tag + 0xa2) = 0x11;
    *(unsigned short*)(tag + 0xa4) = fieldA4;
    *(unsigned short*)(tag + 0xa6) = 5;
    *(unsigned short*)(tag + 0xa8) = 6;
    *(unsigned short*)(tag + 0xaa) = 6;
    *(unsigned short*)(tag + 0xac) = 0xa;
    *(unsigned short*)(tag + 0xae) = 0x10;
    unsigned char zero = 0;
    tag[0xb1] = zero;
    tag[0xb5] = 1;
    tag[0xb6] = 1;
    void* buf = *(void**)(obj + 0xf8);
    memset(buf, zero, 0x960);
    int fmt = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xe0), 0x4274);
    sprintf((char*)buf, (const char*)(long)fmt);
    func_0205d304(tag, buf, 0, 0, 0, 0, 0, 0);
}
