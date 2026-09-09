#include <globaldefs.h>

extern char strPlttNum;
extern "C" int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// Appends the "<PLTT=%d>" control tag to a message string being built and returns the string's new
// total length. PLTT is the palette: pre-baked <PLTT=15>, <PLTT=11>, <PLTT=13> and <PLTT=9> sit
// just before the format string, and the tag parser's token table further on lists PLTT= alongside
// WHITE, YELLOW, PINK and RED as separate tokens, so the argument is a text-palette index rather
// than a packed colour. Same shape as AppendFrameTag and AppendXYTag: find the end of the string,
// sprintf the tag there, return the new length.
extern "C" ARM int AppendPaletteTag(char* dst, int palette) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &strPlttNum, palette)) - dst;
}
