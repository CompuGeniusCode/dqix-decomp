#include <globaldefs.h>

ARM signed char GetField1b_02237e9c(void);
ARM void SetField_022274c0_022274c0(int);
void DispatchFieldValueThenSetup_0222a890(void);

// USA: func_ov031_0222a86c
ARM void AdvanceIfField1bNotNeg2_0222a86c(void) {
    if (GetField1b_02237e9c() == -2) {
        return;
    }
    SetField_022274c0_022274c0((int)DispatchFieldValueThenSetup_0222a890);
}
