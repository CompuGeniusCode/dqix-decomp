#include <globaldefs.h>

extern "C" void func_ov001_0215a134(void* p);
extern "C" void func_ov001_02158ae4(void);

struct Data02165880_a9b4 { char pad0[0x1c]; char* field1c; char pad1[4]; int field24; };
extern Data02165880_a9b4 data_ov001_02165880;

struct Data021658b8_a9b4 { char pad0[0xe4]; int field_e4; };
extern Data021658b8_a9b4 data_ov001_021658b8;

// USA: func_ov001_0215a9b4  (semantic: Func_0215a9b4)
extern "C" ARM int func_ov001_0215a9b4(void) {
    int i;
    for (i = 0; i < 0x18; i++) {
        func_ov001_0215a134(data_ov001_02165880.field1c + i * 0x588);
    }
    if (data_ov001_021658b8.field_e4 != 0 && data_ov001_02165880.field24 != 0) {
        func_ov001_02158ae4();
    }
    return 1;
}
