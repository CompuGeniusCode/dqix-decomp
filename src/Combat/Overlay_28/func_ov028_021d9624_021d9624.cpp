#include <globaldefs.h>

struct Obj9624 {
    char pad[0x80];
    unsigned char f80;
    char pad81[3];
    unsigned int p84;
    unsigned int p88;
    char pad8c[0x98 - 0x8c];
    unsigned int f98;
};

class PMFClass021d8d40;
int DispatchHandlerTable_021d8d40(PMFClass021d8d40* obj1, unsigned short arg2);
unsigned long long GetCurrentTimestamp(void);

// USA: func_ov028_021d9624
extern "C" ARM void func_ov028_021d9624(Obj9624* obj) {
    unsigned char f80 = obj->f80;
    if (f80 != 0) return;
    DispatchHandlerTable_021d8d40((PMFClass021d8d40*)obj, 2);
    if (f80 == 0 && obj->f80 == 1) {
        unsigned long long ts = GetCurrentTimestamp();
        obj->p84 = (unsigned int)ts;
        obj->p88 = (unsigned int)(ts >> 32);
        obj->f98 = 0;
    }
}
