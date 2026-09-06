#include <globaldefs.h>

struct Entry0200173c {
    int field0;
    int field4;
};

extern "C" int func_02001878(struct Entry0200173c* p);
extern unsigned char data_020eebe0[];

// USA: func_0200173c
ARM int Scan0200173c(void) {
    int found = 0;
    for (int i = 0; i < 3; i++) {
        struct Entry0200173c* p = (struct Entry0200173c*)(data_020eebe0 + i * 0x4c);
        if (((p->field4 >> 7) & 7) != 0) {
            if (func_02001878(p) != 0) {
                found = -1;
            }
        }
    }
    return found;
}
