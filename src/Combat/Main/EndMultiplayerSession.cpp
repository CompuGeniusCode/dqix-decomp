#include <globaldefs.h>

extern "C" void SuspendVCountMatchIrq();
extern "C" void func_0202dd28();
extern "C" int func_0202b1f4(int* outPtr, int unused);
extern "C" void func_0202aec0(void* obj);
extern "C" void PopVCountInterruptState(void);
void SleepCurrentContext(unsigned int);
extern "C" int func_0202d6a8(void);
extern "C" void func_0202dd98(void);
extern "C" int func_0202df10();

// Ends the wireless session; it is the registered destructor of the object GetMultiplayerState
// returns, reached through the forwarder func_0202c7a8. It waits out a shutdown already in
// flight on the state word at data_021015a0+0x10, capped at 5000 turns, runs func_0202dd98, then
// func_0202b1f4, which raises the disconnect notice and forces that word to 3, and last
// func_0202df10, which sets it to 3 and issues wireless command 2. SuspendVCountMatchIrq/PopVCountInterruptState
// bracket the body with interrupts off, and func_0202aec0 wipes the session block on every exit.
extern "C" ARM unsigned char EndMultiplayerSession(int* obj) {
    int result = 0;
    SuspendVCountMatchIrq();
    if (*obj != 0) {
        int count = 0;
        while (func_0202d6a8() == 3) {
            count++;
            if (count > 5000) {
                func_0202dd28();
                result = func_0202b1f4(obj, 1);
                if (result == 3) {
                    func_0202aec0(obj);
                    PopVCountInterruptState();
                    return (unsigned char)result;
                }
                break;
            }
            SleepCurrentContext(1);
        }

        func_0202dd98();
        result = func_0202b1f4(obj, 1);
        if (result == 3) {
            func_0202aec0(obj);
            PopVCountInterruptState();
            return (unsigned char)result;
        }
        if (result != 0) {
            func_0202dd28();
            result = func_0202b1f4(obj, 1);
            if (result == 3) {
                func_0202aec0(obj);
                PopVCountInterruptState();
                return (unsigned char)result;
            }
        }
        func_0202df10();
    }
    func_0202aec0(obj);
    PopVCountInterruptState();
    return (unsigned char)result;
}
