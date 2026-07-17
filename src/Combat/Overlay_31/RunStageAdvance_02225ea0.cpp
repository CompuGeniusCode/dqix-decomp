#include <globaldefs.h>

struct Header_0223bd28;
extern "C" void _Z26ExtractPackedHiLo_0223bd28P15Header_0223bd28iPjS1_(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_022266b0(int, int);
extern "C" void func_ov031_022269d8(void);
extern "C" void func_ov031_0223e2b8(void*, void*);
extern "C" void _Z23RunFourStagesB_02225f14v();

struct Struct02225ea0_holder { unsigned char pad[0x40]; Header_0223bd28* header; };
struct Struct02225ea0_base { Struct02225ea0_holder* field0; };
extern Struct02225ea0_base data_ov031_02250c00;

// USA: func_ov031_02225ea0
#pragma optimize_for_size off
ARM void RunStageAdvance_02225ea0(void* a) {
    unsigned int local1, local0;
    _Z26ExtractPackedHiLo_0223bd28P15Header_0223bd28iPjS1_(data_ov031_02250c00.field0->header, 0, &local1, &local0);
    int v = (int)local0 - 0xc;
    local0 = v;
    if (v > 0xaa) {
        func_ov031_022266b0(4, v);
        return;
    }
    func_ov031_022266b0(4, 0xaa);
    func_ov031_022269d8();
    func_ov031_0223e2b8(a, (void*)_Z23RunFourStagesB_02225f14v);
}
