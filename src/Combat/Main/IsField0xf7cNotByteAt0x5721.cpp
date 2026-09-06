#include <globaldefs.h>
int GetByteField0x5721(struct BattleStruct*);
void* GetPtrField0x2a04(struct BattleStruct*);


// USA: func_0206852c
ARM int IsField0xf7cNotByteAt0x5721(void* arg) {
    unsigned char* p = (unsigned char*)GetPtrField0x2a04((struct BattleStruct*)(arg));
    int v = GetByteField0x5721((struct BattleStruct*)(arg));
    return p[0xf7c] != v;
}
