#include <globaldefs.h>

struct Struct02075db0;
int ForwardTableValue02075db0(struct Struct02075db0* s, int a, int b);

// USA: func_ov023_021fb818  (semantic: SnapToTableAndClearFlags_021fb818)
extern "C" ARM int func_ov023_021fb818(void* obj) {
    unsigned char flagA = *(unsigned char*)((char*)obj + 0xb0);
    int dx = 0;
    int dy = 0;
    if (flagA != 0) {
        dx = 1;
        dy = dx;
    } else {
        unsigned char flagB = *(unsigned char*)((char*)obj + 0xb1);
        if (flagB != 0) {
            dx = dx - 1;
            dy = 1;
        }
    }
    ForwardTableValue02075db0((struct Struct02075db0*)((char*)obj + 0x20),
        *(int*)((char*)obj + 0xa8) + dx,
        *(int*)((char*)obj + 0xac) + dy);
    *(unsigned char*)((char*)obj + 0xb0) = 0;
    *(unsigned char*)((char*)obj + 0xb1) = 0;
    return *(int*)((char*)obj + 0x1c);
}
