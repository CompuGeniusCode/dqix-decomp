#include <globaldefs.h>

extern "C" void func_ov023_021dd344(void* p);

struct CallIfFlag0x800_021571ccStruct {
    unsigned char pad[0x1258];
    unsigned short flags;
};

// USA: func_ov006_021571cc
ARM void CallIfFlag_021571cc_021571cc(struct CallIfFlag0x800_021571ccStruct* s) {
    int flagSet = (s->flags & 0x800) != 0;
    if (flagSet) {
        func_ov023_021dd344((char*)s + 0x2e4 + 0x800);
    }
}
