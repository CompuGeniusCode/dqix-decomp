#include <globaldefs.h>

struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, int val);
void InitBattleAndControllerState(void* param);
extern "C" int func_ov017_0218b5b0(void);

// USA: func_020d9a58
ARM void InitBattleIfListHasId0x1c(void* param) {
    int base = func_ov017_0218b5b0();
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + 0x3000 + 0x6fc);
    if (ListContainsId(list, 0x1c)) {
        func_02046a8c(list, *(int*)(base + 0x3000 + 0xb14));
        func_02046a8c(list, *(int*)(base + 0x3000 + 0x70c));
    }
    InitBattleAndControllerState(param);
}
