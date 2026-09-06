#include <globaldefs.h>

// USA: func_ov000_021634c8
ARM void AppendUniqueShort021634c8(char* obj, int val) {
    int i;
    for (i = 0; i < *(short*)(obj + 0x6f00 + 0xc2); i++) {
        if (val == *(short*)(obj + i * 2 + 0x6f00 + 0xba)) break;
    }
    if (i != *(short*)(obj + 0x6f00 + 0xc2)) return;
    {
        short* countPtr = (short*)(obj + 0x6f00 + 0xc2);
        int freshCount = *countPtr;
        short* elemPtr = (short*)(obj + *(short*)(obj + 0x6f00 + 0xc2) * 2 + 0x6f00 + 0xba);
        *countPtr = freshCount + 1;
        *elemPtr = (short)val;
    }
}
