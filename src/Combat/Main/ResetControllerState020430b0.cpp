#include <globaldefs.h>

struct Struct02043110;
ARM void ClearField8ViaPointer0x440(struct Struct02043110* s);

// USA: func_020430b0
ARM void ResetControllerState020430b0(char* self) {
    ClearField8ViaPointer0x440((struct Struct02043110*)(self + 0x19e0));
    *(void**)(self + 0x1e20) = (void*)(self + 0x930);
    ClearField8ViaPointer0x440((struct Struct02043110*)(self + 0x19e0));
    *(void**)(self + 0x1e20) = (void*)(self + 0x914);
    *(char*)(self + 0x19b1) = 0;
    *(char*)(self + 0x19ae) = 0;
    *(char*)(self + 0x19af) = 0;
    *(char*)(self + 0x19bd) = 0;
    *(int*)(self + 0x1838) = -1;
    *(int*)(self + 0x183c) = 0;
}
