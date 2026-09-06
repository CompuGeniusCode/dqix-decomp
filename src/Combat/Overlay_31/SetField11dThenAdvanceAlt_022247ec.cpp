#include <globaldefs.h>

struct EntityStruct022247ec { unsigned char pad[0x11d]; unsigned char field11d; };
extern EntityStruct022247ec* data_ov031_02250bfc;
extern "C" void func_ov031_02224f20(int);
extern "C" void func_ov031_02236878(int);

// USA: func_ov031_022247ec
ARM void SetField11dThenAdvanceAlt_022247ec(void) {
    func_ov031_02224f20(data_ov031_02250bfc->field11d == 1 ? 0 : 1);
    func_ov031_02236878(1);
}
