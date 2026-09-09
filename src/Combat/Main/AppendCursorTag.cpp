#include <globaldefs.h>

extern char strCursorNum;
extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// Appends "<CURSOR=%d>" to the string being built and returns the new total length. One of the tag
// writers from 0x02041a28 that assemble the text-layout markup used by menus and messages; the
// argument is the index of the entry the cursor sits on, taken from base+0x1d6a in
// func_ov000_021775a4 and from a short in func_ov002_0215c178, both of which emit the frame tag,
// then this, then a run of name tags.
extern "C" ARM int AppendCursorTag(char* dst, int cursor) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &strCursorNum, cursor)) - dst;
}
