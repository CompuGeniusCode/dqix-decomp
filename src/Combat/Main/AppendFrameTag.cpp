#include <globaldefs.h>

extern "C" int StringLength(const char* str);
extern "C" int sprintf(char* buffer, const char* fmt, ...);
extern "C" const char strFrameNumNumNumNumNum[];

// Appends "<FRAME=%d,%d,%d,%d,%d>" -- the format string at 0x020efee4 -- to the end of an existing
// message string, and returns the string's new total length. One of a run of siblings for the other
// window markup tags: func_02041c64 emits <WIRE=>, func_02041cc0 <LINE=>, func_02041cf4 <LINEX=>
// and func_02041d48 <LINEY=>. The first number is the selection index the caller then repeats to
// AppendCursorTag and AppendSelectableRegionTag, so it names the region the frame belongs to; the
// other four are constants at the call site, 8,5,5,5 in every menu caller except the two ov013
// message builders, which pass 9,3,6,2 and 8,3,6,2. What those four mean is not established.
extern "C" ARM int AppendFrameTag(char* msg, int cursor, int unknownArg2, int unknownArg3, int unknownArg4, int unknownArg5) {
    char* end = msg + StringLength(msg);
    return (end + sprintf(end, strFrameNumNumNumNumNum, cursor, unknownArg2, unknownArg3, unknownArg4, unknownArg5)) - msg;
}
