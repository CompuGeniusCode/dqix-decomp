#include <globaldefs.h>

struct Entry0200173c {
    int field0;
    unsigned int pad7 : 7;
    unsigned int flag3 : 3;
    unsigned int pad2 : 22;
};

extern "C" int func_02001878(struct Entry0200173c* p);
extern unsigned char data_020eebe0[];

// USA: func_0200173c
ARM int Scan0200173c(void) {
    unsigned char* base = data_020eebe0;
    int found = 0;
    int idx = 1;
    unsigned char* p = base;
    do {
        struct Entry0200173c* e = (struct Entry0200173c*)p;
        if (e->flag3 != 0) {
            if (func_02001878(e) != 0) {
                found = -1;
            }
        }
        if (idx < 3) {
            int off = idx * 0x4c;
            p = base + off;
            idx = idx + 1;
        } else {
            p = 0;
        }
    } while (p != 0);
    return found;
}
