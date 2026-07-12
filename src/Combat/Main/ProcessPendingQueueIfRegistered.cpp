#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);
int EnqueueEvent0x0C(int a, int b, int c, int d);
extern "C" void func_020bcd30(void* obj, int flag);

struct Actor020bce2c {
    char pad0[0x24];    /* 0x00 */
    int field24;        /* 0x24 */
    char pad28[0x10];   /* 0x28 */
    int field38;        /* 0x38 */
    char pad3c[4];       /* 0x3c */
    int field40;        /* 0x40 */
    int field44;        /* 0x44 */
};

// USA: func_020bce2c
ARM void ProcessPendingQueueIfRegistered(struct Actor020bce2c* obj) {
    if (!((obj->field24 << 30) >> 31)) {
        return;
    }
    if (obj->field38 != 0) {
        int flag = 1;
        do {
            unsigned int mask = DisableInterrupts();
            func_020bcd30(obj, flag);
            RestoreInterrupts(mask);
        } while (obj->field38 != 0);
    }
    EnqueueEvent0x0C(obj->field44, 0, 1 << obj->field40, 0);
}
