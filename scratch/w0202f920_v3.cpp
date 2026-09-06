#include <globaldefs.h>

struct Flags78c {
    unsigned int pad0 : 3;
    int bit3 : 1;
    int bit4 : 1;
    unsigned int pad1 : 27;
};

struct BitStreamStruct {
    unsigned char pad[0x78c];
    struct Flags78c flags78c;
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
    do {
        int ok = 1;
        if (!obj->flags78c.bit3) {
            if (!obj->flags78c.bit4) {
                ok = 0;
            }
        }
        func_020d974c();
        if (!ok) {
            return;
        }
        RunWhenCounterZero020d9788(1);
    } while (1);
}
