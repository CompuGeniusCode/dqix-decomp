#include <globaldefs.h>

struct Struct0205e16c;
ARM void ClearThreeWords0205e16c(struct Struct0205e16c* p);
extern "C" void func_0205e22c(void* obj);

struct BattleElem0202c7bc {
    unsigned char pad[0x14];
    unsigned short at14;
    unsigned short at16;
    unsigned int at18;
};

// USA: func_0202c7bc
ARM void* ResetBattleArray0202c7bc(void* obj) {
    struct BattleElem0202c7bc* p = (struct BattleElem0202c7bc*)obj;
    struct BattleElem0202c7bc* end = (struct BattleElem0202c7bc*)((char*)obj + 0x1500);
    do {
        p->at14 = 0;
        p->at16 = 0;
        p->at18 = 0;
        p++;
    } while (p < end);
    ClearThreeWords0205e16c((struct Struct0205e16c*)((char*)obj + 0x1500));
    ClearThreeWords0205e16c((struct Struct0205e16c*)((char*)obj + 0x150c));
    ClearThreeWords0205e16c((struct Struct0205e16c*)((char*)obj + 0x1518));
    func_0205e22c(obj);
    return obj;
}
