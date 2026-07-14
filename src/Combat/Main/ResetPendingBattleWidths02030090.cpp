#include <globaldefs.h>

struct BattleWidth020305c8;
struct Struct0202f700;

extern "C" void func_020d970c();
extern "C" void func_020d974c();
int ClearPendingAndAccumulate(struct BattleWidth020305c8* obj, unsigned short* ptr);
void ClearFieldsAndSetLowNibble(struct Struct0202f700* s);

// USA: func_02030090
ARM void ResetPendingBattleWidths02030090(void* objRaw) {
    char* obj = (char*)objRaw;
    func_020d970c();
    char* elem = obj + 0x128;
    int i = 0;
    while (i < *(int*)(obj + 0x124)) {
        ClearPendingAndAccumulate((struct BattleWidth020305c8*)objRaw, (unsigned short*)(elem + 0x40));
        ClearFieldsAndSetLowNibble((struct Struct0202f700*)elem);
        i++;
        elem += 0x44;
    }
    *(int*)(obj + 0x124) = 0;
    *(int*)(obj + 0x118) = 0;
    *(int*)(obj + 0x788) = 0;
    volatile int* flags = (int*)(obj + 0x78c);
    *flags &= ~2;
    *flags = (*flags & ~1) | 1;
    *flags |= 4;
    func_020d974c();
}
