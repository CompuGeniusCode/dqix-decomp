#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
unsigned int ComputeRatio_02175898(char* obj, void* s);
extern "C" void func_ov003_02176798(void* obj);

// USA: func_ov003_02175924
ARM int TrySpendResource_02175924(char* obj) {
    void* ptrField = GetPtrField0x2a04(GetBattleStruct());
    short key = *(short*)(obj + 0x1000 + 0x3a);
    struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(obj + 0x74 + 0x800), key);
    if (elem == 0) {
        return 0;
    }
    unsigned int ratio = ComputeRatio_02175898(obj, elem);
    unsigned int cost = *(unsigned char*)(obj + 0x1000 + 0x3c) * ratio;
    unsigned int available = *(unsigned int*)((char*)ptrField + 0xf6c);
    if (available < cost) {
        return 0;
    }
    available = available - cost;
    *(unsigned int*)((char*)ptrField + 0xf6c) = available;
    func_ov003_02176798(obj);
    *(unsigned char*)(obj + 0x1000 + 0x4f) = 1;
    return 1;
}
