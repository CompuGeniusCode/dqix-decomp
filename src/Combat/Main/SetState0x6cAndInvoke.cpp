#include <globaldefs.h>

struct Callback_0202a91c {
    char unk[0x6c];
    unsigned char state;
    char unk2[0xf];
    void (*callback)(struct Callback_0202a91c*);
};

// USA: func_0202a91c
ARM void SetState0x6cAndInvoke(struct Callback_0202a91c* obj) {
    if (obj->state == 1) {
        return;
    }
    obj->state = 1;
    if (obj->callback == 0) {
        return;
    }
    obj->callback(obj);
}
