#include <globaldefs.h>

void* GetData02107930(void);

struct Obj0207b108;
int ScaleByteToPercent0207b108(struct Obj0207b108* obj);
struct Obj0207b154;
int UpdateScaledCounter0207b154(struct Obj0207b154* obj);

struct Obj0207b1a4 {
    char pad0[0x12];
    unsigned char field0x12;
    unsigned char pad1[1];
    union {
        struct {
            unsigned char lastIdx : 2;
            unsigned char pad2 : 1;
            unsigned char bits3to6 : 4;
            unsigned char bit7 : 1;
        };
        unsigned char raw14;
    };
};

// USA: func_0207b1a4
ARM void UpdateStatusFlag0207b1a4(struct Obj0207b1a4* self) {
    if (self->bits3to6 == 0) {
        return;
    }
    int idx = *(int*)((char*)GetData02107930() + 0x98);
    if (self->lastIdx != idx || self->bit7) {
        int mask = 1 << idx;
        if (self->bits3to6 & mask) {
            ScaleByteToPercent0207b108((struct Obj0207b108*)self);
        } else {
            UpdateScaledCounter0207b154((struct Obj0207b154*)self);
        }
        if (self->bit7) {
            self->field0x12 = 1;
            self->bit7 = 0;
        }
    }
    self->raw14 = (self->raw14 & ~3) | ((unsigned char)idx & 3);
}
