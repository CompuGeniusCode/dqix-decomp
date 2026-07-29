#include <globaldefs.h>

struct ActionState0201fbe0 {
    unsigned char state;
    unsigned char subState;
    unsigned char b2;
    unsigned char pad3;
    unsigned short field4;
    unsigned char pad[0xe];
};
void ClearActionState(struct ActionState0201fbe0* s, int force);

extern struct ActionState0201fbe0 data_020fdc60[4];

// USA: func_02027304  (semantic: ClearActionStateForIdOrAll02027304)
extern "C" ARM void func_02027304(unsigned char* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            ClearActionState(&data_020fdc60[i], 0);
        }
        return;
    }
    if (id >= 4) return;
    {
        int i;
        unsigned char* p;
        for (i = 0; i < 4; i++) {
            p = obj + i;
            if (id == p[0x758]) {
                ClearActionState(&data_020fdc60[i], 0);
                return;
            }
        }
    }
}
