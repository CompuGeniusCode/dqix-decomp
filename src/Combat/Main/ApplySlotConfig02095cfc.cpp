#include <globaldefs.h>

extern "C" int func_0205ec34(int);
extern "C" void func_0209645c(int, int);
extern "C" void func_02095ff0(int, int);
void SetNibbleFieldTo3IfValid0206e100(int base, int index);

// USA: func_02095cfc
ARM void ApplySlotConfig02095cfc(int arg0, int arg1) {
    SetNibbleFieldTo3IfValid0206e100(func_0205ec34(arg0), arg1);
    func_0209645c(arg0, arg1);
    func_02095ff0(arg0, arg1);
}
