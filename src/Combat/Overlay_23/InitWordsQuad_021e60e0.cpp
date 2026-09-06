#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
extern "C" void __clear(void*, int);
void SetWords_021e60c4_021e60c4(void* obj, struct Words021e60c4* src);

// USA: func_ov023_021e60e0
ARM void InitWordsQuad_021e60e0(void* obj, unsigned int val) {
    struct Words021e60c4 local;
    __clear(&local, 0xc);
    local.b = val;
    SetWords_021e60c4_021e60c4(obj, &local);
    SetWords_021e60c4_021e60c4((char*)obj + 0x8 + 0x400, &local);
    SetWords_021e60c4_021e60c4((char*)obj + 0xac, &local);
    SetWords_021e60c4_021e60c4((char*)obj + 0x35c, &local);
}
