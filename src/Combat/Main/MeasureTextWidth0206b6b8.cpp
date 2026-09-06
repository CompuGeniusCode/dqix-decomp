#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0206b6b8 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

struct Entry0206b6b8* FindEntryByKey0204254c(int key, int tableIdx);
extern "C" void func_02042b98(unsigned char* obj, int a, int b, int c, int d);

// USA: func_0206b6b8
ARM void MeasureTextWidth0206b6b8(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x50);
    int count = 0;

    for (;;) {
        if (*p == 0) break;

        unsigned short ch2, ch;
        memcpy(&ch, p, 2);
        if ((ch & 0xff00) == 0xff00) {
            memcpy(&ch2, p, 2);
            if (ch2 == 0xff01 || ch2 == 0xff0c || ch2 == 0xff0d) break;
            if (ch2 == 0xff18) count++;
            p += 2;
        } else {
            int tableIdx = (obj + 0x1000)[0x9dc];
            int advance = 1;
            struct Entry0206b6b8* e = FindEntryByKey0204254c((int)p, tableIdx);
            if (e) advance = e->field5;
            p += advance;
        }
    }

    int glyphWidth = *(int*)(obj + 0x1000 + 0x864);
    int a = (count - 1) * glyphWidth + 8;
    a = (0xc0 - a) >> 1;
    int b = a - 0x10;
    int c = 0xc0 - b;
    func_02042b98(obj, 2, b, 0xfc, c);
}
