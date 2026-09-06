#include <globaldefs.h>

struct PairStruct;
extern "C" void _ZN8Object3D32ShallowCloneModelAndAnimationsToEPS_(struct PairStruct* src, struct PairStruct* dst);

// USA: func_02072adc
ARM void CopyPairAndStoreField(struct PairStruct* src, struct PairStruct* dst) {
    _ZN8Object3D32ShallowCloneModelAndAnimationsToEPS_(src, dst);
    *(short*)((char*)dst + 0x178) = *(int*)((char*)src + 0xac);
}
