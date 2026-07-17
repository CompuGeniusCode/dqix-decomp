#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
ARM int IsPtr02290c44Null_02227840(void);
ARM void SetField_022274c0_022274c0(int);
void CallStubPair_0222a274(void);

// USA: func_ov031_0222a244
ARM void AdvanceUnlessFlagsSet_0222a244(void) {
    if (GetField9AtIndex_0223c054(0) != 0) {
        return;
    }
    if (IsPtr02290c44Null_02227840() == 0) {
        return;
    }
    SetField_022274c0_022274c0((int)CallStubPair_0222a274);
}
