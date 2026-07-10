#include <globaldefs.h>

struct ActionSlot020d8b4c;

int CheckStateByType020d8a68(unsigned char*);
int ResetActionSlot020d8b4c(ActionSlot020d8b4c*);

// USA: func_020d91a8
ARM int ReleaseActionSlot020d91a8(int* out, unsigned char* slot) {
    if (CheckStateByType020d8a68(slot)) {
        ResetActionSlot020d8b4c((ActionSlot020d8b4c*)slot);
    }
    *out = 0;
    return 1;
}
