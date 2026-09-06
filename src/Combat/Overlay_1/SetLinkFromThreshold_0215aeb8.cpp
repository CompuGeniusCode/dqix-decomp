#include <globaldefs.h>

struct Data02114e54_aeb8 { char pad[0x44]; unsigned int field44; char pad2[0x54 - 0x44 - 4]; unsigned char field54; };
extern Data02114e54_aeb8 data_02114e54;
extern "C" void func_ov017_021d6134(void* obj, unsigned int val);

// USA: func_ov001_0215aeb8
ARM int SetLinkFromThreshold_0215aeb8(void* obj) {
    int v = (data_02114e54.field54 != 0 && data_02114e54.field44 < 10) ? 1 : 0;
    func_ov017_021d6134(obj, v);
    return 1;
}
