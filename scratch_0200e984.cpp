#include <globaldefs.h>

struct ByteRecordList0200e984 {
    int count;
    int unk4;
    int unk8;
    unsigned char* records;
};

extern "C" int func_0200eff0(void* ctx, unsigned int value, unsigned int* buf);

// USA: func_0200e984
ARM int func_0200e984(void* ctx, ByteRecordList0200e984* list) {
    unsigned char* p = list->records;
    unsigned int buf[2];
    unsigned int i = 0;
    if ((unsigned int)list->count <= 0) return 0;
    do {
        unsigned int value = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
        buf[1] = value;
        if (func_0200eff0(ctx, value, buf) != 0) {
            return 1;
        }
        p += 4;
        i++;
    } while (i < (unsigned int)list->count);
    return 0;
}
