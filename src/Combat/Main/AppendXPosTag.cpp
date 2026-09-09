#include <globaldefs.h>

extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char data_020efe78;

// Appends "<X=%d>" to a window markup string and returns the new total length, so the calls chain.
// The value is a pixel column: func_ov013_02185424 centres a line with (0xf0 - measured width) / 2
// against the 240-pixel screen. Neighbouring functions emit the rest of the family -- <Y=>, <XY=>,
// <W=>, <H=>, <SIZE=>, <PLTT=>, <CURSOR=>, <FRAME=>, <TITLE=>, <ENC=>, <SDRC=>, <LINEX=>, <SLT=>
// and more besides -- and the parser side is the keyword table just past data/pack_lv5/font_lv5.gp2
// around 0x020f1150.
extern "C" ARM int AppendXPosTag(char* dst, int x) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020efe78, x)) - dst;
}
