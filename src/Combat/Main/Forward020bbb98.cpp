#include <globaldefs.h>

extern "C" int LoadToSubBG2ScreenData(int, int, unsigned int);

// USA: func_020bbb98
ARM int Forward020bbb98(int a, int b, unsigned int c) {
    return LoadToSubBG2ScreenData(a, b, c);
}
