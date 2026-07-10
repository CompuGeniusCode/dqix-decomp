#include <globaldefs.h>

struct PairStruct;
void CopyFields0x8And0xC(struct PairStruct* src, struct PairStruct* dst);

// USA: func_02072adc
ARM void CopyPairAndStoreField(struct PairStruct* src, struct PairStruct* dst) {
    CopyFields0x8And0xC(src, dst);
    *(short*)((char*)dst + 0x178) = *(int*)((char*)src + 0xac);
}
