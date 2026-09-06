#include <globaldefs.h>

// USA: func_ov000_0216346c
ARM void AppendUniqueShort0216346c(char* obj, int val) {
    int i;
    for (i = 0; i < *(short*)(obj + 0x6e00 + 0xfa); i++) {
        if (val == *(short*)(obj + i * 2 + 0x6e00 + 0xf0)) break;
    }
    if (i != *(short*)(obj + 0x6e00 + 0xfa)) return;
    {
        short* countPtr = (short*)(obj + 0x6e00 + 0xfa);
        int freshCount = *countPtr;
        short* elemPtr = (short*)(obj + *(short*)(obj + 0x6e00 + 0xfa) * 2 + 0x6e00 + 0xf0);
        *countPtr = freshCount + 1;
        *elemPtr = (short)val;
    }
}
