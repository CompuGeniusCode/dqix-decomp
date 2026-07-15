#include <globaldefs.h>

extern "C" int func_ov004_02157054(void);
extern "C" int func_ov023_021fbdec(void);

// USA: func_ov004_02157088
ARM int CheckThenNotify_02157088(void) {
    if (func_ov004_02157054() == 0) return 0;
    return func_ov023_021fbdec();
}
