#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void*, int);

struct Node02175f80 { char pad[0x28]; int field28; };

// USA: func_ov000_02175f80
ARM int CountNodesFieldBitClear02175f80(void* obj) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        struct Node02175f80* node = (struct Node02175f80*)func_ov000_02161318(obj, i);
        if (node) {
            if ((node->field28 & 1) == 0) count++;
        }
    }
    return count;
}
