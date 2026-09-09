#include <globaldefs.h>

extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern const char strNNumStrN;

// Appends "<N=%d>%s</N>" to a window-markup string, alongside the sibling emitters for <FRAME=>,
// <WIRE=> and <LINE=>. In the parser's keyword table at 0x020f0238, N= and /N sit next to CURSOR=
// and UA=, UB=, DA=, DB=; func_ov002_0215dd0c and func_ov000_021775a4 emit one <N=i> per choice in
// a loop, and func_ov000_02179ed8 hands the same number to AppendFrameTag, AppendCursorTag and
// this. So the numbered region presumably marks a selectable choice rather than the name plate the
// machine name suggested. Callers are all menu code in ov000, ov002, ov003 and ov012.
extern "C" ARM int AppendSelectableRegionTag(char* dst, int n, const char* name) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &strNNumStrN, n, name)) - dst;
}
