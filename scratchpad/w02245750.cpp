#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_ov031_0224c94e;

struct DataX02245750 { unsigned char pad[0x28]; int* field28; };
extern DataX02245750 data_ov031_02291e04;

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* VectorizedInvertedMemcpy(void* dst, void* src, int n);

struct Param02245750 {
    unsigned char pad0[4];
    int field4;
    int field8;
    unsigned char field0xc[8];
};

// USA: func_ov031_02245750
extern "C" ARM int func_ov031_02245750(void* unused0, Param02245750* p) {
    char* found = strstr((char*)p, &data_ov031_0224c94e);
    if (found == NULL) return 0;

    int i;
    for (i = 0; i < 0xe; i++) {
        if (data_ov031_02291e04.field28[i] == p->field4) break;
    }
    if (i == 0xe) return 0;

    char* base = (char*)(int)func_ov017_0218b5b0() + 0x3000;
    char* entry = *(char**)(base + 0xb48);
    entry[0x28] = (unsigned char)i;
    entry[0x29] = (unsigned char)p->field8;
    VectorizedInvertedMemcpy(p->field0xc, entry + 0x2a, 8);
    return 1;
}
