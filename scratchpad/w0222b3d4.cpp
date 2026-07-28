#include <globaldefs.h>

extern "C" void func_ov031_0222b168(void);
extern "C" void func_ov031_0222b1a0(void);
extern "C" void func_ov031_0222b1a4(void);
extern "C" void* func_ov031_022368e0(void);
extern "C" void func_ov031_0222b1f0(void);
void SetField_022274c0_022274c0(int);

struct Struct0222b3d4 { unsigned char pad[2]; unsigned short field2; };
extern Struct0222b3d4 data_ov031_02290c80;

// USA: func_ov031_0222b3d4
ARM void TickFrameCounterAndMaybeReload_0222b3d4(void) {
    func_ov031_0222b168();
    func_ov031_0222b1a0();
    func_ov031_0222b1a4();
    data_ov031_02290c80.field2++;
    if (data_ov031_02290c80.field2 < 0x438) return;
    func_ov031_022368e0();
    SetField_022274c0_022274c0((int)func_ov031_0222b1f0);
}
