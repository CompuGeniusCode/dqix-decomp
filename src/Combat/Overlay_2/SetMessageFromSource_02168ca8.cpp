#include <globaldefs.h>
#include "std_library_functions.h"

extern int StringLength(const char* s);
extern char data_ov002_0216d2fc[];

struct CopySrc02168ca8 { int a; int b; int c; };
struct MsgBuf02168ca8 {
    int a;
    char* b;
    int c;
    char pad[0x38];
    char buf[0x200];
};

// USA: func_ov002_02168ca8  (semantic: SetMessageFromSource_02168ca8)
extern "C" ARM void func_ov002_02168ca8(MsgBuf02168ca8* dst, CopySrc02168ca8* src) {
    if (src == 0) return;
    dst->a = src->a;
    dst->b = (char*)src->b;
    dst->c = src->c;
    dst->b = dst->buf;
    int count = src->b;
    if (count == 0) return;
    memset(dst->buf, 0, 0x200);
    sprintf(dst->buf + StringLength((const char*)dst->buf), data_ov002_0216d2fc, count);
}
