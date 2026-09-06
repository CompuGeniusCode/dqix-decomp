#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" int func_ov031_022191e0(void);
extern "C" void func_ov031_02219080(void);
unsigned int NormalizeIndex_022135ac(unsigned int x);
int GetGlobalField1000_02219220(void);

struct Handler02215478 {
    unsigned int field0;
    unsigned int field4;
    unsigned int field8;
    unsigned int fieldc;
    int field10;
    unsigned char field14;
    unsigned char field15;
};

// USA: func_ov031_02215478
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02215478(char* a0) {
    struct Handler02215478* h = (struct Handler02215478*)func_ov031_022133f8(1);
    int field1000 = func_ov031_022191e0();
    if (field1000 != 0) {
        unsigned int idx = NormalizeIndex_022135ac(*(unsigned char*)(a0 + 0xd0d));
        if (h->field15 == idx) {
            h->field10 = GetGlobalField1000_02219220();
        }
        func_ov031_02219080();
        if (field1000 == 0xb) return 0xf;
        unsigned char idx2 = *(unsigned char*)(a0 + 0xd13);
        *(unsigned char*)(a0 + idx2 * 4 + 0x444) = 1;
        return 0xb;
    }
    return 0xe;
}
