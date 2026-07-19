#include <globaldefs.h>

char* GetOffset400_02235c70(void);
extern "C" void func_ov031_02223998(int);

// USA: func_ov031_02223a0c  (semantic: CallField400Plus2_02223a0c)
extern "C" ARM void func_ov031_02223a0c(void) {
    func_ov031_02223998(*(unsigned char*)(GetOffset400_02235c70() + 0xf4) + 2);
}
