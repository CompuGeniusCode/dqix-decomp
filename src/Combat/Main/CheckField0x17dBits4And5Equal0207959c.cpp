#include <globaldefs.h>

struct Obj0207959c {
    unsigned char pad[0x17d];
    unsigned char flags;
};

// USA: func_0207959c
ARM int CheckField0x17dBits4And5Equal0207959c(struct Obj0207959c* obj, int mode) {
    unsigned char flags = obj->flags;
    if (flags & 8) {
        return ((unsigned char)(flags >> 4) & 3) == mode;
    }
    return 0;
}
