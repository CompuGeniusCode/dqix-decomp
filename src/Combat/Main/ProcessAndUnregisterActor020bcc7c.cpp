#include <globaldefs.h>

void ProcessQueueUntilValueCommitted020d2680(unsigned int);
extern "C" void func_020d1f0c(void*, int, int, int);
extern "C" void func_020d24c4(int);
int GetInterruptSafeQueueField(void);
void RemoveFromGlobalList02111804(void* node);
void RemoveFromGlobalList02111800(void* node);

struct Actor020bccf0;
void UnregisterActorFromGlobalList020bccf0(struct Actor020bccf0* obj);

struct Obj020bcc7c {
    char pad0[0x24];
    int bit0 : 1;
    int bit1 : 1;                 /* 0x24 bit 1 */
    int bitrest : 30;
    char pad28[0x40 - 0x28];
    int field40;                  /* 0x40 */
    void* field44;                /* 0x44 */
};

// USA: func_020bcc7c
ARM void ProcessAndUnregisterActor020bcc7c(struct Obj020bcc7c* obj) {
    if (obj->bit1) {
        func_020d1f0c(obj->field44, 0, 1 << obj->field40, 0);
        RemoveFromGlobalList02111804((char*)obj + 0x8);
        RemoveFromGlobalList02111800((char*)obj + 0x14);
        obj->bit1 = 0;
        int x = GetInterruptSafeQueueField();
        func_020d24c4(1);
        ProcessQueueUntilValueCommitted020d2680((unsigned int)x);
    }
    UnregisterActorFromGlobalList020bccf0((struct Actor020bccf0*)obj);
}
