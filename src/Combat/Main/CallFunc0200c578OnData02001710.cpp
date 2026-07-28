#include <globaldefs.h>

extern void* data_020eecc8;
extern "C" int func_0200c578(void* p);

// USA: func_02001710  (semantic: CallFunc0200c578OnData_02001710)
extern "C" ARM int func_02001710(void) {
    return func_0200c578(data_020eecc8);
}
