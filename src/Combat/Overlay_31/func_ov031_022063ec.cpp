#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int state);

struct BlockedContextList;
void BlockCurrentContext(BlockedContextList* p);

struct Queue02206368 {
    char pad0[0x100];
    unsigned short field100;
    char pad1[0x104 - 0x100 - 2];
    char field104;
};

struct Obj02206368 {
    char pad[0x68];
    Queue02206368* q;
};

extern "C" ARM int func_ov031_022063ec(Obj02206368* obj);

// USA: func_ov031_02206368  (semantic: ClampAndFetchWithBlock_02206368)
extern "C" ARM int func_ov031_02206368(Obj02206368* obj, int min, int max, int* out, int flags) {
    Queue02206368* q = obj->q;
    if (max > min) {
        max = min;
    }
    unsigned int state = DisableIRQInterrupts();
    int result;
    int bit0 = flags & 1;
    for (;;) {
        result = func_ov031_022063ec(obj);
        if (result >= max) {
            *out = q->field100;
            if (result >= min) {
                result = min;
            }
            break;
        }
        if (!bit0) {
            result = 0;
            break;
        }
        BlockCurrentContext((BlockedContextList*)&q->field104);
    }
    SetIRQInterruptState(state);
    return result;
}
