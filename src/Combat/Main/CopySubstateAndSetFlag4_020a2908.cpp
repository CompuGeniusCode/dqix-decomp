#include <globaldefs.h>

struct Struct020a2928;
ARM struct Struct020a2928* CopyStruct020a2928(struct Struct020a2928* dst, struct Struct020a2928* src);

// USA: func_020a2908
ARM void CopySubstateAndSetFlag4_020a2908(unsigned char* obj, struct Struct020a2928* src) {
    CopyStruct020a2928((struct Struct020a2928*)(obj + 0x298), src);
    obj[0x245] |= 4;
}
