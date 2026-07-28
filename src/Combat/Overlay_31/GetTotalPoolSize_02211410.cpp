#include <globaldefs.h>

int GetConst4816_02210044(void);
int GetConst8f4_0220f3f4(void);

// USA: func_ov031_02211410  (semantic: GetTotalPoolSize_02211410)
extern "C" ARM int func_ov031_02211410(void) {
    int size = 0;
    size += 0x60;
    size += ((unsigned int)(GetConst4816_02210044() + 0x1f) >> 5) << 5;
    return size + (((unsigned int)(GetConst8f4_0220f3f4() + 0x1f) >> 5) << 5);
}
