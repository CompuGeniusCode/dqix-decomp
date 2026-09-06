#include <globaldefs.h>

struct EntryDEC8 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad[0x19];
};

// USA: func_0206dec8
ARM void SetEntry3Bytes(struct EntryDEC8* base, int index, unsigned char a, unsigned char b, unsigned char c) {
    base[index].a = a;
    base[index].b = b;
    base[index].c = c;
}
