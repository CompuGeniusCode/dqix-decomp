#include <globaldefs.h>

signed char GetField1b_02237e9c(void);
extern "C" void func_ov031_02236878(int a);
extern "C" void func_ov031_02237e58(void);
void* StoreFieldAndDispatch_02235060(int v);
void SetField_022274c0_022274c0(int v);

struct HolderData02230e90 {
    unsigned char pad[8];
    unsigned char* ptr;
};
extern struct HolderData02230e90 data_ov031_02290ca0;

extern "C" void func_ov031_02230ed0(void);

// USA: func_ov031_02230e90  (semantic: CheckFieldThenDispatchAndSetHandler_02230e90)
extern "C" ARM void func_ov031_02230e90(void) {
    if (GetField1b_02237e9c() != 0) {
        return;
    }
    func_ov031_02236878(6);
    func_ov031_02237e58();
    int v = *(int*)(data_ov031_02290ca0.ptr + 0xc);
    StoreFieldAndDispatch_02235060(v);
    SetField_022274c0_022274c0((int)func_ov031_02230ed0);
}
