#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);

struct Entry0202fec8 {
    char pad0[0x30];
    short id;
    char pad32[0x38 - 0x32];
    int val1;
    int val2;
    char pad40[0x44 - 0x40];
};

struct List0202fec8 {
    char pad0[0x124];
    int count;
    struct Entry0202fec8 entries[1];
};

// USA: func_0202fec8
ARM void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2) {
    struct Entry0202fec8* e;
    int i;
    func_020d970c();
    *out1 = 0;
    *out2 = 0;
    if (id >= 0) {
        e = obj->entries;
        i = 0;
        while (i < obj->count) {
            if (id == e->id) {
                *out1 = e->val1;
                *out2 = e->val2;
                break;
            }
            i++;
            e++;
        }
    }
    func_020d974c();
}
