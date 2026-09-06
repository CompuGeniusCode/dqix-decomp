#include <globaldefs.h>

void* GetGlobalField0x1c020421a0();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02187480  (semantic: CallFunc02184c68UnlessState0Or3_02187480)
extern "C" ARM int func_ov011_02187480(unsigned int obj) {
    int state = *(int*)((char*)GetGlobalField0x1c020421a0() + 0x9a0);
    int flag = 1;
    if (state == 0 || state == 3) flag = 0;
    func_ov011_02184c68(obj, flag);
    return 1;
}
