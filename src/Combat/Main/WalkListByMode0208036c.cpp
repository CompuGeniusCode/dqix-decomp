#include <globaldefs.h>

struct Node0208036c {
    char pad0[0x18];
    struct Node0208036c* f18;
    struct Node0208036c* f1c;
    struct Node0208036c* f20;
    struct Node0208036c* f24;
    char pad1[0x2a - 0x28];
    unsigned char f2a;
};

struct Flags0208036c {
    unsigned int f0;
};

// USA: func_0208036c
ARM struct Node0208036c* WalkListByMode0208036c(void* unused, struct Node0208036c* start, int mode, struct Flags0208036c* flags, unsigned char setFlag) {
    struct Node0208036c* cur;
    struct Node0208036c* next;
    if (start == NULL) {
        return NULL;
    }
    cur = start;
    switch (mode) {
    case 0x40:
        while ((next = cur->f1c) != NULL) {
            if (next->f2a & 0x2) {
                break;
            }
            cur = next;
        }
        break;
    case 0x80:
        while ((next = cur->f18) != NULL) {
            if (next->f2a & 0x2) {
                break;
            }
            cur = next;
        }
        break;
    case 0x20:
        if (setFlag) {
            flags->f0 |= 0x20;
        } else {
            while ((next = cur->f24) != NULL) {
                if (next->f2a & 0x2) {
                    break;
                }
                cur = next;
            }
        }
        break;
    case 0x10:
        if (setFlag) {
            flags->f0 |= 0x10;
        } else {
            while ((next = cur->f20) != NULL) {
                if (next->f2a & 0x2) {
                    break;
                }
                cur = next;
            }
        }
        break;
    }
    return cur;
}
