#include <globaldefs.h>

struct Obj0202e71c {
    unsigned char pad[0x70];
    int f70;
    int f74;
    int f78;
};

extern "C" void func_0202e5d8(struct Obj0202e71c* obj, int a, int b, int c);

// USA: func_0202e71c
ARM void SetField78Clamped0202e71c(struct Obj0202e71c* obj, int p) {
    obj->f78 = p;
    int cur = obj->f74;
    if (0.0f < (float)cur) {
        int limit = cur + 0x1000;
        if (obj->f78 < limit) obj->f78 = limit;
    } else {
        int limit = 0x1000 - cur;
        if (obj->f78 < limit) obj->f78 = limit;
    }
    if (obj->f78 < 0x1000)
        obj->f78 = 0x1000;
    func_0202e5d8(obj, obj->f70, obj->f74, obj->f78);
}
