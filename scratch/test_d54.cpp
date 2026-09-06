#include <globaldefs.h>

extern "C" int ReadByteAt17122_02156858(void);

// USA: func_ov001_ffffffff
ARM int CommaTest_ffffffff(void* obj) {
    if ((obj, ReadByteAt17122_02156858())) {
        return 1;
    }
    return 0;
}
