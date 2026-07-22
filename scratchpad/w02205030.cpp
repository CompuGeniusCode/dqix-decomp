#include <globaldefs.h>

struct InitData020c7de4 {
    int a; int b; int c; int d;
    int e; int f; int g; int h;
};
void InitStruct020c7de4(InitData020c7de4* s, int e, int f);
void CallGlobalWithArg_02205174(int v);

struct AllocVTable_02205030 { char pad[0x18]; void* (*alloc)(int); };
extern void* data_ov031_022496a4;
extern int data_ov031_0224e204;
extern void* data_ov031_0224e200;

// USA: func_ov031_02205030
ARM int AllocateAndInitEntries_02205030(int count) {
    int sizeIdx = (count * 4 + 3) & ~3;
    int sizeEntry = (count * 0x2c + 3) & ~3;
    void* (*alloc)(int) = ((AllocVTable_02205030*)data_ov031_022496a4)->alloc;
    void* p = alloc(sizeEntry + sizeIdx);
    if (p == 0) return -1;
    InitStruct020c7de4((InitData020c7de4*)&data_ov031_0224e204, (int)p, count);
    char* cur = (char*)p + sizeIdx;
    if (count > 0) {
        do {
            CallGlobalWithArg_02205174((int)cur);
            count--;
            cur += 0x2c;
        } while (count > 0);
    }
    data_ov031_0224e200 = p;
    return 0;
}
