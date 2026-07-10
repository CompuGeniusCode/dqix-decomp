#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);

struct Entry0202fe68 {
    char pad0[0x30];
    short key;
    signed char val;
    char pad33[0x44 - 0x33];
};

struct List0202fe68 {
    char pad0[0x124];
    int count;
    struct Entry0202fe68 entries[1];
};

// USA: func_0202fe68
ARM int LookupListValueByKey(struct List0202fe68* obj, int key) {
    int result = -1;
    func_020d970c();
    if (key >= 0) {
        struct Entry0202fe68* e = obj->entries;
        int i = 0;
        while (i < obj->count) {
            if (key == e->key) {
                result = (e->val << 0x1c) >> 0x1c;
                break;
            }
            i++;
            e++;
        }
    }
    func_020d974c();
    return result;
}
