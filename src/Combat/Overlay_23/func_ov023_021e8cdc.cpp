#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov023_021fdd6c;
extern "C" void* _Z15GetBattleStructv();
extern "C" void* __clear(void* dst, int count);
extern "C" int func_020426bc(void* src, void* dst, int flag);
extern "C" int _Z12StringLengthPKc(const char* s);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int key, int tableIdx);
extern "C" void func_02042764(void* a, void* b, int flag);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};
extern "C" struct Entry0204254c* _Z22FindEntryByKey0204254cii(int key, int tableIdx);
extern "C" int _Z10AppendXTagPci(char* dst, int x);
extern "C" void _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" int _Z10AppendYTagPci(char* dst, int y);

// USA: func_ov023_021e8cdc
extern "C" ARM void func_ov023_021e8cdc(char* obj) {
    int len;
    if (*(int*)(obj + 0x5f4) == 0) return;
    char* dst = *(char**)(obj + 0x5d8);

    char* battle = (char*)_Z15GetBattleStructv() + 0x29c + 0x5400;

    char buf[0x43a];
    __clear(buf, 0x3a);
    __clear(buf + 0x3a, 0x400);

    char* src = *(char**)(obj + 0x600);
    if (src != 0) {
        len = func_020426bc(src, buf, 1);
    } else {
        len = _Z12StringLengthPKc(battle + 8);
        memcpy(buf, battle + 8, len);
    }

    signed char idxByte = (signed char)_Z27FindEntryIndexByKey020424e4ii((int)&data_ov023_021fdd6c, 1);
    for (; len < 0x39; len++) buf[len] = idxByte;

    func_02042764(buf, buf + 0x3a, 1);

    char* p = buf + 0x3a;
    int x = 0xf;
    int resetX = x;
    int y = 8;
    int col = 0;
    for (;;) {
        if (*p == 0) return;
        int step = 1;
        struct Entry0204254c* e = _Z22FindEntryByKey0204254cii((int)p, step);
        if (e != 0) {
            _Z10AppendXTagPci(dst, x);
            _Z20AppendString02042058PcPKc(dst, (const char*)e->val);
            step = e->field5;
        }
        col++;
        p += step;
        x += 0xc;
        if (col == 0x13) {
            y += 0x13;
            x = resetX;
            col = 0;
            _Z10AppendYTagPci(dst, y);
        }
    }
}
