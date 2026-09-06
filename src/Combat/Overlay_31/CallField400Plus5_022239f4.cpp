#include <globaldefs.h>

char* GetOffset400_02235c70(void);
extern "C" void func_ov031_02223998(int);

// USA: func_ov031_022239f4  (semantic: CallField400Plus5_022239f4)
extern "C" ARM void func_ov031_022239f4(void) {
    func_ov031_02223998(*(unsigned char*)(GetOffset400_02235c70() + 0xf4) + 5);
}
