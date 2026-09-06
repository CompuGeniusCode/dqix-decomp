#include <globaldefs.h>

struct Obj0208becc;
void* CheckTypeAndReturnNode_02165e70_02165e70(void* a, int key);
void SetFieldD2IfChanged0208becc(struct Obj0208becc* obj, int value, unsigned char b);

// USA: func_ov004_02167648  (semantic: SetNodeFieldD2IfType21_02167648)
extern "C" ARM int func_ov004_02167648(void* a) {
    void* node = CheckTypeAndReturnNode_02165e70_02165e70(a, 7);
    if (node) {
        SetFieldD2IfChanged0208becc((struct Obj0208becc*)((char*)node + 0x34), 0x270f, 0);
    }
    return 0;
}
