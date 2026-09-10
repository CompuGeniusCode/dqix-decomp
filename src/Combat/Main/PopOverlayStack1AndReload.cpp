#include <globaldefs.h>

extern "C" void func_020a1940(int);
extern volatile unsigned char data_02109da4[2];
extern signed char data_02109da6[];
extern signed char data_020f1977[];

// The game keeps two 8-deep stacks of ids at data_02109da4, one per counter byte, and this pops the
// second. An id is translated through a 7-byte table - data_020f1977 here, data_020f1962 for the
// other stack - and handed to func_020a1940, which takes the resource mutex and runs
// LoadCompressedOverlay and DecompressAndStaticInitializeOverlay. Both tables are seven zero bytes
// in the ROM and nothing writes them, so every id resolves to overlay 0. The argument asks for the
// reload; ov017 callers all pass 1 after popping the other stack, and zero just drops the entry.
extern "C" ARM void PopOverlayStack1AndReload(int flag) {
    if (data_02109da4[1] == 0) return;
    data_02109da4[1]--;
    if (flag == 0 || data_02109da4[1] == 0) return;
    signed char i = data_02109da6[data_02109da4[1] - 1];
    func_020a1940(data_020f1977[i]);
}
