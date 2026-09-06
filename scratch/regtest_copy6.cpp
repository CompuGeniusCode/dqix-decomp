#include <globaldefs.h>
#include "std_library_functions.h"

ARM void TestMemcpy12_regtest6(void* src, void* dst) {
    memcpy(dst, src, 12);
    memcpy(dst, src, 12);
}
