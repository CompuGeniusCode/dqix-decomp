#include <globaldefs.h>

struct BitStreamStruct {
    unsigned char pad[0x78c];
    int flags78c;
};

extern "C" void func_02030110(void* obj);
void ShiftInBitAt0x788(BitStreamStruct* obj);
extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);
void RunWhenCounterZero020d9788(int arg);

// USA: func_0202f920
ARM void PollBitStream0202f920(BitStreamStruct* obj) {
    func_02030110(obj);
    ShiftInBitAt0x788(obj);
    func_020d970c();
    for (;;) {
        int ok = 1;
        if (!(obj->flags78c & 8)) {
            if (!(obj->flags78c & 0x10)) {
                ok = 0;
            }
        }
        func_020d974c();
        if (!ok) {
            return;
        }
        RunWhenCounterZero020d9788(1);
    }
}
