#include <globaldefs.h>

extern "C" void func_0204e1c8(int flag, void* entry, void* p2, void* p3, int a, int b, int c, int d);

// USA: func_ov023_021e2030
ARM void DrawGrid2x2Cells_021e2030(int a, int paramB, int paramC, void* cursor) {
    short outerVal;
    for (int y = 0; y < 2; y++) {
        outerVal = (short)(paramC + (y << 3));
        for (int x = 0; x < 2; x++) {
            short innerVal = (short)(paramB + (x << 3));
            func_0204e1c8(a, cursor, (void*)(int)innerVal, (void*)(int)outerVal, 8, 8, 0xf0, 0xf);
            cursor = (char*)cursor + 0x20;
        }
    }
}
