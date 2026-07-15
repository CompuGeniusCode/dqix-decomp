#include <globaldefs.h>

extern "C" void* func_ov001_02158dcc(void*);

struct Payload3_02159250 { int c, d, e; };

// USA: func_ov001_02159250
ARM void EnqueueEventType18_02159250(void* obj, int b, Payload3_02159250 payload) {
    int* node = (int*)func_ov001_02158dcc(obj);
    if (node != NULL) {
        node[0] = 0x12;
        node[1] = payload.c;
        node[2] = payload.d;
        node[3] = payload.e;
        *(int*)((char*)obj + 0xa20) = b;
    }
}
