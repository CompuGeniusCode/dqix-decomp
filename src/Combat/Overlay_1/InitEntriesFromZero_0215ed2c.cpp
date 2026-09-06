#include <globaldefs.h>

extern int data_ov001_021658b8;
extern "C" void* func_ov017_021d612c(void*);
extern "C" void func_ov001_0215ec94(void*, int);

// USA: func_ov001_0215ed2c
ARM int InitEntriesFromZero_0215ed2c(void* entries, int count) {
    *(int*)((char*)&data_ov001_021658b8 + 0x88) = 0;
    int i;
    for (i = 0; i < count; i++) {
        void* mapped = func_ov017_021d612c(entries);
        entries = (char*)entries + 8;
        func_ov001_0215ec94(mapped, i);
    }
    return 1;
}
