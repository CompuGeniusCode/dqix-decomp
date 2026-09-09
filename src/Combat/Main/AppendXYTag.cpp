#include <globaldefs.h>

extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char strXyNumNum;

// Appends the "<XY=%d,%d>" control tag to a message string under construction and returns the
// string's new total length. The tag moves the drawing position; the single-axis <X=%d> and <Y=%d>
// forms sit immediately before it in the same literal block, next to <W=>, <H=>, <WH=>, <FRAME=>,
// <LINE=> and the rest of the window markup that the text parser understands. Whether the two
// numbers are pixels or character cells is not established.
extern "C" ARM int AppendXYTag(char* dst, int x, int y) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &strXyNumNum, x, y)) - dst;
}
