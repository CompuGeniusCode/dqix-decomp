#include <globaldefs.h>

extern "C" int func_0200eff0(void* obj, unsigned int value, void* outBuf);

struct List0200e984 {
    unsigned int count;
    unsigned char pad[8];
    unsigned char* bytes;
};

ARM int CheckByteArrayAgainst0200e984(void* obj, List0200e984* list) {
    unsigned int localBuf[2];
    unsigned char* p = list->bytes;
    unsigned int i;
    for (i = 0; i < list->count; i++) {
        unsigned int v = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
        localBuf[1] = v;
        if (func_0200eff0(obj, v, localBuf) != 0) return 1;
        p += 4;
    }
    return 0;
}
