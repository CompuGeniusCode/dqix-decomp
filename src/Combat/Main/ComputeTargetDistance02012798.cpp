#include <globaldefs.h>

struct DistObj02012798 {
    char pad00[0x20];
    unsigned short x;
    unsigned short y;
    char pad24[0x38 - 0x24];
    int tx;
    int ty;
};

extern "C" int func_0200b074(int);
extern "C" int func_0200b454(int);
extern "C" int func_0200af44(int);

// USA: func_02012798
ARM int ComputeTargetDistance02012798(struct DistObj02012798* obj) {
    int dx = obj->tx - obj->x;
    int dy = obj->ty - obj->y;
    return func_0200af44(func_0200b454(func_0200b074(dx * dx + dy * dy)));
}
