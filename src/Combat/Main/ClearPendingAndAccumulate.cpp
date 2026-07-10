#include <globaldefs.h>

struct BattleWidth020305c8;
void AccumulateMaxWidth020305c8(struct BattleWidth020305c8*);
extern "C" void func_020d970c();
extern "C" void func_020d974c();

// USA: func_02030584
ARM int ClearPendingAndAccumulate(struct BattleWidth020305c8* obj, unsigned short* ptr) {
    int result = 0;
    func_020d970c();
    if (ptr[1] != 0) {
        ptr[0] = 0;
        ptr[1] = 0;
        result = 1;
        AccumulateMaxWidth020305c8(obj);
    }
    func_020d974c();
    return result;
}
