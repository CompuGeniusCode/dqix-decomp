#include <globaldefs.h>

extern "C" void func_0202e5d8(void*, int, int, int);

struct CamState0202e6c0 {
    char pad[0x70];
    int f70;
    int f74;
    int f78;
};

// USA: func_0202e6c0
ARM void ClampField74BySign(struct CamState0202e6c0* obj, int value) {
    int limit;
    obj->f74 = value;
    if (0.0f < (float)obj->f74) {
        limit = obj->f78 - 0x1000;
        if (limit < obj->f74) obj->f74 = limit;
    } else {
        limit = 0x1000 - obj->f78;
        if (obj->f74 < limit) obj->f74 = limit;
    }
    func_0202e5d8(obj, obj->f70, obj->f74, obj->f78);
}
