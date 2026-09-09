#include <globaldefs.h>

extern char strTitleNumStrTitle;

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" ARM int StringLength(const char* s);

// Appends <TITLE=%d>%s</TITLE> to the message being composed in the buffer and returns the
// buffer's new total length. One of a run of one-tag-each appenders from 0x02041cc0 onward:
// <LINE>, <SIZE>, <PLTT>, <CURSOR>, <UA>, <DB>, <TEN>, <TALK> and <XR>. Watch the argument order,
// the string is the second parameter and the number the third. Callers are all menu text (17 in
// ov002 topmenu, the rest in ov003, ov012 prof, ov013 skillup and ov023), so the number is
// presumably a player-title id, but nothing here establishes that.
extern "C" ARM int AppendTitleTag(char* buf, int a, int b) {
    char* end = buf + StringLength(buf);
    return (end + sprintf(end, &strTitleNumStrTitle, b, a)) - buf;
}
