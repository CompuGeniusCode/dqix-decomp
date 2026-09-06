#include <globaldefs.h>

void SetField0x7cClearFields0x1ec0x1ee(unsigned char* obj, unsigned short val);
extern "C" int GetSomeInt(void);

// USA: func_ov001_ffffffff
ARM void ConvTest_ffffffff(unsigned char* field) {
    int wrapped = GetSomeInt();
    SetField0x7cClearFields0x1ec0x1ee(field, wrapped);
}
