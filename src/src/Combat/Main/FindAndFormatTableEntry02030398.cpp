#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);

struct FormatObj0202f760;
int FormatPathWithTableEntry_0202f760(struct FormatObj0202f760* obj, char* dst);

struct Entry02030398 {
    char pad0[0x30];
    short key;
    char pad33[0x44 - 0x32];
};

struct List02030398 {
    char pad0[0x124];
    int count;
    struct Entry02030398 entries[1];
};

// USA: func_02030398
ARM int FindAndFormatTableEntry02030398(struct List02030398* obj, int key, char* dst) {
    int result = 0;
    func_020d970c();
    if (key >= 0) {
        struct Entry02030398* e = obj->entries;
        int i = 0;
        while (i < obj->count) {
            if (key == e->key) {
                FormatPathWithTableEntry_0202f760((struct FormatObj0202f760*)e, dst);
                result = 1;
                break;
            }
            i++;
            e++;
        }
    }
    func_020d974c();
    return result;
}
