#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);

struct Entry0202fdd0 {
    char pad0[0x30];
    short key;
    signed char val;
    char pad33[0x44 - 0x33];
};

struct List0202fdd0 {
    char pad0[0x124];
    int count;
    struct Entry0202fdd0 entries[1];
};

// USA: func_0202fdd0  (semantic: Func0202fdd0)
extern "C" ARM int func_0202fdd0(struct List0202fdd0* obj, int key) {
    int result = -1;
    func_020d970c();
    if (key >= 0) {
        struct Entry0202fdd0* e = obj->entries;
        int i = 0;
        while (i < obj->count) {
            if (key == e->key) {
                int val = (e->val << 0x1c) >> 0x1c;
                if (val == 2) {
                    result = 1;
                } else if (val == 3) {
                    result = -1;
                } else if (val == 4) {
                    result = -1;
                } else {
                    result = 0;
                }
                break;
            }
            i++;
            e++;
        }
    }
    func_020d974c();
    return result;
}
