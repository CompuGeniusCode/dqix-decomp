#include <globaldefs.h>

struct Obj021e8a20 {
    int a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

void Init021e8a20(struct Obj021e8a20* obj);

// USA: func_ov025_021eb3e0
extern "C" ARM void* func_ov025_021eb3e0(void* obj) {
    struct Obj021e8a20* rec = (struct Obj021e8a20*)((char*)obj + 0x194 + 0x400);
    unsigned char i = 0;
    while (i < 4) {
        if (rec->e == 0) {
            Init021e8a20(rec);
            return rec;
        }
        i++;
        rec++;
    }
    return 0;
}
