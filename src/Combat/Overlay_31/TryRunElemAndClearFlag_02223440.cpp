#include <globaldefs.h>

void *TailCallElemAtIndex30_0223c7c4(int idx);
extern unsigned char data_ov031_02250bac;

// USA: func_ov031_02223440  (semantic: TryRunElemAndClearFlag_02223440)
extern "C" ARM int func_ov031_02223440(void) {
    if (data_ov031_02250bac == 0) return 0;
    TailCallElemAtIndex30_0223c7c4(1);
    data_ov031_02250bac = 0;
    return 1;
}
