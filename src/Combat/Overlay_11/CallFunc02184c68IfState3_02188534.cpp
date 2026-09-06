#include <globaldefs.h>

void* GetGlobalField0x1c020421a0();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02188534  (semantic: CallFunc02184c68IfState3_02188534)
extern "C" ARM int func_ov011_02188534(unsigned int obj) {
    int state = *(int*)((char*)GetGlobalField0x1c020421a0() + 0x9a0);
    int flag = 0;
    if (state == 3) flag = 1;
    func_ov011_02184c68(obj, flag);
    return 1;
}
