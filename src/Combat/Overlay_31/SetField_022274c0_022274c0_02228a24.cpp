#include <globaldefs.h>

void RegisterSlotEntry_0223c078(int, int, int, int);
void SetHiByteFromMode_0223cb68(int, int);
ARM void SetField_022274c0_022274c0(int);
void AdvanceIfNotFlag0_02228a58(void);

// USA: func_ov031_02228a24
ARM void ConfigureThenDispatch_02228a24(void) {
    RegisterSlotEntry_0223c078(2, 0, 0x15, 8);
    SetHiByteFromMode_0223cb68(0, 0x15);
    SetField_022274c0_022274c0((int)AdvanceIfNotFlag0_02228a58);
}
