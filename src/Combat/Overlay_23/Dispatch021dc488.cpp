#include <globaldefs.h>

struct Obj021dc488 {
    char pad[0x776];
    unsigned char idx076;
};

typedef void (Obj021dc488::*Fn021dc488)();

extern "C" void func_ov023_021db110(void* p);
extern void* data_ov023_021ffa0c;

struct Guard021dc488 {
    int pad[7];
    int flags;
};
extern Guard021dc488 data_ov023_021ff9e0;

struct Src021dc488 {
    int x, y;
};
extern Src021dc488 data_020e6d5c;

struct Dst021dc488 {
    char pad[0x40];
    int a, b;
};
extern Dst021dc488 data_ov023_021fda60;

extern Fn021dc488 data_ov023_021fda88[];

// USA: func_ov023_021dc488
ARM int Dispatch021dc488(Obj021dc488* obj) {
    func_ov023_021db110(&data_ov023_021ffa0c);
    if (!(data_ov023_021ff9e0.flags & 1)) {
        data_ov023_021fda60.a = data_020e6d5c.x;
        data_ov023_021fda60.b = data_020e6d5c.y;
        data_ov023_021ff9e0.flags |= 1;
    }
    unsigned char idx = obj->idx076;
    if (data_ov023_021fda88[idx] == 0) return 1;
    (obj->*data_ov023_021fda88[idx])();
    return 0;
}
