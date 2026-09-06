#include <globaldefs.h>

extern "C" void LoadToSubBGStandardPalette(int, int, unsigned int);

// USA: func_020bbbbc
ARM void Forward020bbbbc(int a, int b, unsigned int c) {
    LoadToSubBGStandardPalette(a, b, c);
}
