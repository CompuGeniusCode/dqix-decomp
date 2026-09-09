#include <globaldefs.h>

extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" const char strFrameNumNumNumNumNum[];

// Appends "<FRAME=%d,%d,%d,%d,%d>" -- the format string at 0x020efee4 -- to the end of an existing
// message string, and returns the string's new total length. One of a run of siblings for the other
// window markup tags: func_02041c64 emits <WIRE=>, func_02041cc0 <LINE=>, func_02041cf4 <LINEX=>
// and func_02041d48 <LINEY=>. What the five numbers mean is not established.
extern "C" ARM int AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, strFrameNumNumNumNumNum, a1, a2, a3, a4, a5)) - dst;
}
