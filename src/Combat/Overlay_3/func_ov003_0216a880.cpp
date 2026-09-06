#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern int IsField0x9cEqual3(unsigned char* obj);

struct Struct0200fb08;
extern int NormalizeField5_0200fb08(struct Struct0200fb08*);

extern "C" void func_0205ac40(void* dst, void* src);

extern unsigned char data_ov003_0217f530;
extern unsigned char data_ov003_0217f532;
extern unsigned char data_ov003_0217f533;
extern unsigned char data_ov003_0217f531;

// USA: func_ov003_0216a880
extern "C" ARM void func_ov003_0216a880(unsigned char* obj) {
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0xe4), 2);
    if (e == 0) return;
    if (!IsField0x9cEqual3((unsigned char*)e)) return;

    int key = NormalizeField5_0200fb08((struct Struct0200fb08*)GetBattleStruct());

    unsigned int lo = 0x90000;
    unsigned int hi = 0xc6000;
    unsigned int idx = 6;
    int i;
    for (i = 0; i < 5; i++) {
        if (key == (&data_ov003_0217f530)[i * 4]) {
            lo = (&data_ov003_0217f532)[i * 4] << 0xc;
            idx = (&data_ov003_0217f531)[i * 4];
            hi = (&data_ov003_0217f533)[i * 4] << 0xc;
            break;
        }
    }

    unsigned int off0 = idx * 0x28;
    unsigned char* p0 = *(unsigned char**)(obj + 0x4d4) + off0;
    *(unsigned int*)(p0 + 0x14) = lo;
    *(unsigned int*)(p0 + 0x18) = 0x61000;
    func_0205ac40(obj + 0x480, *(unsigned char**)(obj + 0x4d4) + off0);

    unsigned int off1 = (idx + 1) * 0x28;
    unsigned char* p1 = *(unsigned char**)(obj + 0x4d4) + off1;
    *(unsigned int*)(p1 + 0x14) = hi;
    *(unsigned int*)(p1 + 0x18) = 0x61000;
    func_0205ac40(obj + 0x480, *(unsigned char**)(obj + 0x4d4) + off1);
}
