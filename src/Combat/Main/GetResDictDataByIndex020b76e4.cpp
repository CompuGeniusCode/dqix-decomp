#include <globaldefs.h>

// USA: func_020b76e4
ARM void* GetResDictDataByIndex020b76e4(unsigned char* block, unsigned int index) {
    unsigned char* base;
    unsigned char* dict;
    unsigned char* entry;
    unsigned short off;
    unsigned short es;
    if (block != NULL) {
        base = block + *(int*)(block + *(unsigned short*)(block + 0xc));
        dict = base + 8;
        if (dict != NULL && index < *(unsigned char*)(base + 9)) {
            off = *(unsigned short*)(base + 0xe);
            es = *(unsigned short*)(dict + off);
            entry = dict + off + 4 + es * index;
        } else {
            entry = NULL;
        }
        if (entry != NULL) {
            return base + *(int*)entry;
        }
    }
    return NULL;
}
