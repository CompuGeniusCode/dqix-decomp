#include <globaldefs.h>

void SetField0x7cClearFields0x1ec0x1ee(unsigned char* obj, unsigned short val);

// USA: func_ov001_ffffffff
ARM void ConvTest2_ffffffff(unsigned char* field, short wrapped) {
    SetField0x7cClearFields0x1ec0x1ee(field, wrapped);
}
