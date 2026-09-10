#include <globaldefs.h>

extern int data_020e7a94[];
extern "C" int FindFontCharIndex(int key, int tableIdx);
extern "C" void* func_020425b4(int idx, int tableIdx);
extern "C" int func_020425e4(int prevGlyphIndex, int glyphIndex, int tableIdx);

struct FontGlyph {
    int unknown0;
    char advance;
    signed char charByteLength : 6;
    signed char unused2 : 2;
    char unknown6[2];
};

// Walks the string against font table data_0210782c[fontId], adding each glyph's advance (entry
// byte 4, plus one) and the kerning value func_020425e4 gives for the previous and current
// glyph indices; the six-bit field at byte 5 is the character's byte length, so multi-byte characters
// work. A missing character costs data_020e7a94[fontId] + 1 and resets the kerning state, and the
// trailing -1 drops the spacing after the last glyph. Callers subtract the result from an x
// coordinate, so the unit is pixels; every one passes 0 or 1, picking one of two font descriptors.
// A glyph entry is eight bytes -- func_020425b4 indexes the array at table+0x10 with a shift of
// three and bounds it by the count at table+0x4 -- and the word at +0 is not read here.
extern "C" ARM int MeasureStringWidth(char* str, int fontId) {
    if (str == 0) return 0;
    int defaultAdvance = data_020e7a94[fontId] & 0xff;
    int resetState = 0xff;
    int state = resetState;
    int masked;
    int total = 0;
    for (;;) {
        if (*str == 0) break;
        int delta = defaultAdvance + 1;
        int idx = FindFontCharIndex((int)str, fontId);
        if (idx < 0) {
            state = resetState;
            str++;
        } else {
            masked = idx & 0xff;
            struct FontGlyph* entry = (struct FontGlyph*)func_020425b4(idx, fontId);
            int kerning = func_020425e4(state, masked, fontId);
            state = masked;
            delta = (entry->advance + 1) + kerning;
            str = str + entry->charByteLength;
        }
        total += delta;
    }
    return total - 1;
}
