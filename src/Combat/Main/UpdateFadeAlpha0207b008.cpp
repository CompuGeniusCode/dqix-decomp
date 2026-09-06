#include <globaldefs.h>

struct S02037418;
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);

struct Entry0207b008 {
    unsigned char pad0[0xfc];
    unsigned char field_fc;
    unsigned char pad1[3];
    Entry0207b008* next;
};

struct Obj0207b008 {
    Entry0207b008* list;
    unsigned char pad0[0xd];
    unsigned char flags;
    unsigned char counter;
    unsigned char alpha;
};

// USA: func_0207b008
ARM void UpdateFadeAlpha0207b008(Obj0207b008* obj) {
    Entry0207b008* e;

    if (!(obj->flags & 0x2) && !(obj->flags & 0x4)) return;
    obj->counter--;
    if (obj->flags & 0x2) {
        obj->alpha = (unsigned char)((90 - obj->counter) / 90.0f * 31.0f);
    } else if (obj->flags & 0x4) {
        obj->alpha = (unsigned char)((unsigned int)obj->counter / 90.0f * 31.0f);
    }
    for (e = obj->list; e != NULL; e = e->next) {
        float ratio = (unsigned int)obj->alpha / 31.0f;
        int val = (int)((unsigned int)e->field_fc * ratio);
        _ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)e, val);
    }
    if (obj->counter == 0) {
        obj->counter = 0;
        obj->flags &= ~0x6;
    }
}
