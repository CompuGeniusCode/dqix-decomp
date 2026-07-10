#include <globaldefs.h>

extern "C" unsigned short* func_02012fe4(void);
extern "C" int func_0201b588(unsigned short);

// USA: func_020117f0
ARM int IsGlobalU16InRange(void) {
    return func_0201b588(*func_02012fe4());
}
