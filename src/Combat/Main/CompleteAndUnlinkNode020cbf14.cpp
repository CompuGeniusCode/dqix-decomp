#include <globaldefs.h>

struct Node020cb034 {
    struct Node020cb034* prev;
    struct Node020cb034* next;
    int f8;
    unsigned int fc;
    int f10;
    int f14;
    int f18;
};
void UnlinkAndResetNode020cb034(struct Node020cb034* node, int value);
extern "C" int func_020cb090(struct Node020cb034* obj, int value);
extern "C" int func_020cbc6c(int value);
extern "C" void func_020cbe80(void);

// USA: func_020cbf14
ARM int CompleteAndUnlinkNode020cbf14(struct Node020cb034* obj) {
    int v = func_020cb090(obj, obj->f10);
    UnlinkAndResetNode020cb034(obj, v);
    if (func_020cbc6c(obj->f8) != 0) {
        func_020cbe80();
    }
    return obj->f14 == 0;
}
