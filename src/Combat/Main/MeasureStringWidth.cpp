#include <globaldefs.h>

extern int data_020e7a94[];
extern "C" int func_020424e4(int key, int tableIdx);
extern "C" void* func_020425b4(int idx, int tableIdx);
extern "C" int func_020425e4(int a, int b, int tableIdx);

struct Entry020420e8 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

// Walks the string against font table data_0210782c[fontId], adding each glyph's advance (entry
// byte 4, plus one) and the kerning value func_020425e4 gives for the previous and current
// glyph indices; the six-bit field at byte 5 is the character's byte length, so multi-byte characters
// work. A missing character costs data_020e7a94[fontId] + 1 and resets the kerning state, and the
// trailing -1 drops the spacing after the last glyph. Callers subtract the result from an x
// coordinate, so the unit is pixels; every one passes 0 or 1, picking one of two font descriptors.
extern "C" ARM int MeasureStringWidth(char* str, int id) {
    if (str == 0) return 0;
    int mask = data_020e7a94[id] & 0xff;
    int resetState = 0xff;
    int state = resetState;
    int masked;
    int total = 0;
    for (;;) {
        if (*str == 0) break;
        int delta = mask + 1;
        int idx = func_020424e4((int)str, id);
        if (idx < 0) {
            state = resetState;
            str++;
        } else {
            masked = idx & 0xff;
            struct Entry020420e8* entry = (struct Entry020420e8*)func_020425b4(idx, id);
            int val = func_020425e4(state, masked, id);
            state = masked;
            delta = (entry->pad4 + 1) + val;
            str = str + entry->field5;
        }
        total += delta;
    }
    return total - 1;
}
