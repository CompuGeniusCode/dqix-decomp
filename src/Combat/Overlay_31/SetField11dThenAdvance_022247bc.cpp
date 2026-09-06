#include <globaldefs.h>

struct EntityStruct022247bc { unsigned char pad[0x11d]; unsigned char field11d; };
extern EntityStruct022247bc* data_ov031_02250bfc;
extern "C" void func_ov031_02224f20(int);
extern "C" void func_ov031_02236878(int);

// USA: func_ov031_022247bc
ARM void SetField11dThenAdvance_022247bc(void) {
    func_ov031_02224f20(data_ov031_02250bfc->field11d == 2 ? 0 : 2);
    func_ov031_02236878(1);
}
