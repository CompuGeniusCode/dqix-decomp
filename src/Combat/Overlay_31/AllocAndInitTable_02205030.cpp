#include <globaldefs.h>

struct AllocTable022496a4 { char pad[0x18]; void* (*alloc)(unsigned int); };
extern AllocTable022496a4* data_ov031_022496a4;

struct InitData020c7de4;
extern void InitStruct020c7de4(InitData020c7de4* p, int a, int b);
extern InitData020c7de4 data_ov031_0224e204;

extern void CallGlobalWithArg_02205174(int arg);
extern void* data_ov031_0224e200;

// USA: func_ov031_02205030  (semantic: AllocAndInitTable_02205030)
extern "C" ARM int func_ov031_02205030(int id) {
    unsigned int sizeA = (unsigned int)(id * 44 + 3) & ~3u;
    unsigned int sizeB = (unsigned int)(id * 4 + 3) & ~3u;
    void* alloc = data_ov031_022496a4->alloc(sizeA + sizeB);
    if (alloc == 0) return -1;
    InitStruct020c7de4(&data_ov031_0224e204, (int)alloc, id);
    char* p = (char*)alloc + sizeB;
    if (id > 0) {
        int n = id;
        do {
            CallGlobalWithArg_02205174((int)p);
            n--;
            p += 0x2c;
        } while (n > 0);
    }
    data_ov031_0224e200 = alloc;
    return 0;
}
