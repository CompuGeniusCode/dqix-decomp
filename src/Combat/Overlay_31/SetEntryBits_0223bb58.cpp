#include <globaldefs.h>

struct Entry_0223bb58 {
    unsigned int word0;
    unsigned short hword4;
    unsigned short pad6;
};

// USA: func_ov031_0223bb58  (semantic: SetEntryBits_0223bb58)
extern "C" ARM void func_ov031_0223bb58(void* obj, int idx, int a, int b) {
    Entry_0223bb58* arr = *(Entry_0223bb58**)((char*)obj + 0x8);
    if (idx >= 0) {
        Entry_0223bb58* e = arr + idx;
        e->word0 = (e->word0 & ~0xc00) | (a << 10);
        e->hword4 = (e->hword4 & ~0xf000) | (b << 12);
    } else {
        int i = 0;
        int count = *((unsigned char*)obj + 0xc);
        if (count <= 0) return;
        do {
            Entry_0223bb58* e = arr + i;
            e->word0 = (e->word0 & ~0xc00) | (a << 10);
            i++;
            e->hword4 = (e->hword4 & ~0xf000) | (b << 12);
        } while (i < *((unsigned char*)obj + 0xc));
    }
}
