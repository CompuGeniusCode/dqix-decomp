#include <globaldefs.h>

struct StateA020129b4 {
    char pad00[0x24];
    unsigned short flag24;
    unsigned short flag26;
    char pad28[0x40 - 0x28];
    int val40;
    int val44;
    int val48;
    int val4c;
    char pad50[0x56 - 0x50];
    unsigned char flag56;
    char pad57[0x5f - 0x57];
    unsigned char flag5f;
};

struct DistObj02012798;

int PrepareAndProcess020cddc0(void* obj);
int ComputeTargetDistance02012798(struct DistObj02012798* obj);

// USA: func_020129b4
ARM int UpdateTargetTrackingState(struct StateA020129b4* obj) {
    PrepareAndProcess020cddc0((char*)obj + 0x20);
    if (obj->flag5f == 0) {
        if (obj->flag24 != 0) {
            return 0;
        }
        obj->flag5f = 1;
    }
    if (obj->flag24 != 0 && obj->flag26 == 0) {
        obj->val40 = obj->val40 + 1;
        obj->val48 = 0;
        if (obj->flag56 != 0 && ComputeTargetDistance02012798((struct DistObj02012798*)obj) > 1) {
            obj->val4c = 0;
        } else if (ComputeTargetDistance02012798((struct DistObj02012798*)obj) < 1) {
            obj->val4c = obj->val4c + 1;
        }
    } else {
        obj->flag24 = 0;
        if (obj->val40 != 0) {
            obj->val44 = obj->val40;
        }
        obj->val40 = 0;
        obj->val48 = obj->val48 + 1;
    }
    return 1;
}
