#include <globaldefs.h>

struct GlobalObj0202e6a8 {
    char pad0[0x70];
    int field70;
    int field74;
    int field78;
};

extern "C" void func_0202e5d8(struct GlobalObj0202e6a8*, int, int, int);

// USA: func_0202e6a8
ARM void ApplyField0x70Tail(struct GlobalObj0202e6a8* obj, int value) {
    obj->field70 = value;
    func_0202e5d8(obj, value, obj->field74, obj->field78);
}
