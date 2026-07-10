#include <globaldefs.h>

struct BitStreamStruct;
void ShiftInBitAt0x788(struct BitStreamStruct* obj);
extern int data_02104304[];

// USA: func_0202f7c8
ARM void ShiftInBitOnGlobalObject() {
    struct BitStreamStruct* obj = (struct BitStreamStruct*)data_02104304[1];
    if (obj != NULL) {
        ShiftInBitAt0x788(obj);
    }
}
